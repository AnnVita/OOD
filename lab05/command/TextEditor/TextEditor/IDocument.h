#pragma once
#include "stdafx.h"
#include "ICommand.h"
#include "IParagraph.h"
#include "IImage.h"

using namespace std;
using boost::optional;
using boost::none;

class IDocument
{
public:
	virtual void InsertParagraph(const string& text, optional<size_t> position = none) = 0;
	virtual void InsertImage(const Path& path, int width, int height,
		optional<size_t> position = none) = 0;
	virtual void List(ostream& output) = 0;
	virtual DocumentItemPtr GetItem(size_t index)const = 0;
	virtual void DeleteItem(size_t index) = 0;
	virtual string GetTitle()const = 0;
	virtual void SetTitle(const string & title) = 0;
	virtual bool CanUndo()const = 0;
	virtual void Undo() = 0;
	virtual bool CanRedo()const = 0;
	virtual void Redo() = 0;
	virtual void Save(const Path& path)const = 0;
	virtual ~IDocument() = default;
};