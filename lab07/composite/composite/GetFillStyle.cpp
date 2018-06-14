#include "stdafx.h"
#include "GetFillStyle.h"

std::shared_ptr<IStyle> CGetFillStyle::GetStyle(std::shared_ptr<IShape> shape)
{
	return shape->GetFillStyle();
}
