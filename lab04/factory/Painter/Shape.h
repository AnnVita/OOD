#pragma once
#include "stdafx.h"
#include "EColor.h"
#include "ICanvas.h"
#include "IShape.h"


class CShape : public IShape
{
public:
	CShape();
	//virtual std::unique_ptr<CShape> Clone() const = 0;
	virtual void SetColor(EColor color) override;
	virtual EColor GetColor() const override;
private:
	EColor m_color = EColor::BLUE;
};
