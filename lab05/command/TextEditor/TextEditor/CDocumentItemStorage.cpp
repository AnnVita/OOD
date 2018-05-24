#include "stdafx.h"
#include "CDocumentItemStorage.h"

using namespace std;


CDocumentItemStorage::CDocumentItemStorage()
{}

void CDocumentItemStorage::InsertDocumentItem(const DocumentItemPtr & documentItem, boost::optional<size_t> position)
{
	std::deque<DocumentItemPtr>::iterator positionIterator;
	size_t unwrappedPosition = position.get_value_or(m_documentItems.size());
	m_documentItems.insert(m_documentItems.begin() + unwrappedPosition, documentItem);
	GetItem(unwrappedPosition)->SetDeleteResource(false);
}

void CDocumentItemStorage::DeleteDocumentItem(size_t position)
{
	GetItem(position)->SetDeleteResource(true);
	m_documentItems.erase(m_documentItems.begin() + position);
}

DocumentItemPtr CDocumentItemStorage::GetItem(size_t index)const
{
	return m_documentItems.at(index);
}

ConstDocumentItemPtr CDocumentItemStorage::GetConstItem(size_t index)const
{
	return m_documentItems.at(index);
}

size_t CDocumentItemStorage::GetSize()const
{
	return m_documentItems.size();
}
