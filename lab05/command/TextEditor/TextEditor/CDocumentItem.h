#pragma once
#include "stdafx.h"
#include "IImage.h"
#include "IParagraph.h"
#include "CDocumentItem.h"

using namespace std;

class CDocumentItem
{
public:
	CDocumentItem(const shared_ptr<IImage> & imagePtr = nullptr, const shared_ptr<IParagraph> & paragraphPtr = nullptr);

	shared_ptr<IImage> GetImage() const;
	shared_ptr<IParagraph> GetParagraph() const;

	void SetDeleteResource(bool deleteResource);

	~CDocumentItem() = default;

private:
	shared_ptr<IImage> m_imagePtr = nullptr;
	shared_ptr<IParagraph> m_paragraphPtr = nullptr;
};