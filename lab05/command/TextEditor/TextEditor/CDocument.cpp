#include "stdafx.h"
#include "CDocument.h"
#include "CCommandLog.h"
#include "CChangeStringCommand.h"
#include "CInsertParagraphCommand.h"
#include "CInsertImageCommand.h"
#include "CReplaceTextCommand.h"
#include "CResizeImageCommand.h"
#include "CDeleteItemCommand.h"
#include "CParagraph.h"

using namespace std;
namespace fs = boost::filesystem;

CDocument::CDocument()
{}

void CDocument::SetTitle(const std::string & title)
{
	m_commandHistory.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	m_commandHistory.AddAndExecuteCommand(make_unique<CInsertParagraphCommand>(m_storage, text, position));
}

void CDocument::InsertImage(const Path& path, int width, int height, optional<size_t> position)
{
	m_commandHistory.AddAndExecuteCommand(make_unique<CInsertImageCommand>(m_storage, width, height, path, position));
}

DocumentItemPtr CDocument::GetItem(size_t index)const
{
	return m_storage.GetItem(index);
}

bool CDocument::CanUndo() const
{
	return m_commandHistory.CanUndo();
}

void CDocument::Undo()
{
	if (!CanUndo())
	{
		throw logic_error("Can't undo.");
	}
	m_commandHistory.Undo();
}

bool CDocument::CanRedo() const
{
	return m_commandHistory.CanRedo();
}

void CDocument::Redo()
{
	if (!CanRedo())
	{
		throw logic_error("Can't redo.");
	}
	m_commandHistory.Redo();
}

void CDocument::List(ostream& output)
{
	output << "Title : " << GetTitle() << endl;
	unsigned index = 0;

	for (unsigned i = 0; i < m_storage.GetSize(); ++i)
	{
		ConstDocumentItemPtr documentItem = m_storage.GetConstItem(i);

		shared_ptr<IImage> image = documentItem->GetImage();
		shared_ptr<IParagraph> paragraph = documentItem->GetParagraph();

		if (image != nullptr)
		{
			output << index++ << ". " << "Image : ";
			output << image->GetWidth() << " " << image->GetHeight() << " ";
			output << image->GetPath() << endl;
		}

		if (paragraph != nullptr)
		{
			output << index++ << ". " << "Paragraph : ";
			output << paragraph->GetText() << endl;
		}
	}
}

void CDocument::AddAndExecuteCommand(ICommandPtr && command)
{
	m_commandHistory.AddAndExecuteCommand(move(command));
}

void CDocument::DeleteItem(size_t index)
{
	m_commandHistory.AddAndExecuteCommand(make_unique<CDeleteItemCommand>(m_storage, index));
}

void CDocument::Save(const Path& baseDir)const
{
	if (!fs::exists(baseDir))
	{
		fs::create_directory(baseDir);
	}

	Path imagesDir = baseDir / "images";
	Path indexPath = baseDir / "index.html";

	fs::create_directory(imagesDir);

	CopyResources(imagesDir);

	ofstream indexFile(indexPath.string());

	ToHtml(indexFile);

	indexFile.close();
}

void CDocument::ToHtml(ostream & output)const
{
	output << "<!DOCTYPE html><html><head>"
		<< "<title>" << Encode(GetTitle()) << "</title>"
		<< "</head><body>";

	for (unsigned i = 0; i < m_storage.GetSize(); ++i)
	{
		ConstDocumentItemPtr documentItem = m_storage.GetConstItem(i);
		shared_ptr<IImage> image = documentItem->GetImage();
		shared_ptr<IParagraph> paragraph = documentItem->GetParagraph();

		if (image != nullptr)
		{
			output << "<img width=\"" << image->GetWidth() << "\" height=\"" << image->GetHeight() << "\" src=\"" << Encode(image->GetPath().string()) << "\" />";
		}

		if (paragraph != nullptr)
		{
			output << "<p>" << Encode(paragraph->GetText()) << "</p>";
		}
	}
	output << "</body></html>";
}

void CDocument::CopyResources(const Path& resourcesDir)const
{
	for (unsigned i = 0; i < m_storage.GetSize(); ++i)
	{
		ConstDocumentItemPtr documentItem = m_storage.GetConstItem(i);
		shared_ptr<IImage> image = documentItem->GetImage();

		if (image != nullptr)
		{
			Path imagePath = image->GetPath();
			fs::copy_file(imagePath, resourcesDir / imagePath.filename());
		}
	}
}

std::string CDocument::Encode(std::string str)const
{
	boost::replace_all(str, "<", "&lt;");
	boost::replace_all(str, ">", "&gt;");
	boost::replace_all(str, "\"", "&quot;");
	boost::replace_all(str, "'", "&apos;");
	boost::replace_all(str, "&", "&amp;");
	return str;
}