#pragma once
#include "EColor.h"

class IShape
{
public:
	virtual void SetColor(EColor color) = 0;
	virtual EColor GetColor() const = 0;
	virtual void Draw(ICanvas & canvas) const = 0;
	virtual ~IShape() = default;
};