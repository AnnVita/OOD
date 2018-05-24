#pragma once
#include "stdafx.h"

class CImageImpl
{
public:
	CImageImpl(int width, int height, Path path);
	~CImageImpl();
	Path GetPath()const;
	int GetWidth()const;
	int GetHeight()const;
	void Resize(int width, int height);
	void SetDeleteResource(bool deleteResource);
private:
	int m_width;
	int m_height;
	Path m_path;
	bool m_deleteResource = true;
};

