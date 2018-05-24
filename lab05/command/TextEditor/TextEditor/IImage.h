#pragma once
#include "stdafx.h"

class IImage
{
public:
	virtual boost::filesystem::path GetPath()const = 0;
	virtual int GetWidth()const = 0;
	virtual int GetHeight()const = 0;
	virtual void Resize(int width, int height) = 0;
	virtual void SetDeleteResource(bool deleteResource) = 0;
	virtual ~IImage() = default;
};