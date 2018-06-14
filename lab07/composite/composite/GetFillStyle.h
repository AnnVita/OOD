#pragma once
#include "IGetStyleBehavior.h"

class CGetFillStyle : public IGetStyleBehavior
{
public:
	std::shared_ptr<IStyle> GetStyle(std::shared_ptr<IShape> shape) override;
};

