#pragma once
#include "stdafx.h"
#include "CDocumentItem.h"

using DocumentItemsList = std::deque<DocumentItemPtr>;
class CDocumentItemStorage
{
public:
	CDocumentItemStorage();

	void InsertDocumentItem(const DocumentItemPtr & documentItem, boost::optional<size_t> position);
	void DeleteDocumentItem(size_t position);
	DocumentItemPtr GetItem(size_t index)const;
	ConstDocumentItemPtr GetConstItem(size_t index)const;
	size_t GetSize()const;

private:
	std::deque<DocumentItemPtr> m_documentItems;
};