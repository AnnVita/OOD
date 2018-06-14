#pragma once
#include "SimpleShape.h"
#include "SPoint.h"

class CEllipse : public CSimpleShape
{
public:
	CEllipse(SPoint center, double radiusX, double radiusY);

	void Draw(ICanvas & canvas) final;

	virtual RectDouble GetFrame()const final;
	virtual void SetFrame(const RectDouble & rect) final;

private:
	SPoint m_center = { 0, 0 };
	double m_radiusX = 0;
	double m_radiusY = 0;
	RectDouble m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
};