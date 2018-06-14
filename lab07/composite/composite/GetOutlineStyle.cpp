#include "stdafx.h"
#include "GetOutlineStyle.h"

std::shared_ptr<IStyle> CGetOutlineStyle::GetStyle(std::shared_ptr<IShape> shape)
{
	return shape->GetOutlineStyle();
}