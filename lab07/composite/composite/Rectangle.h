#pragma once
#include "SimpleShape.h"
#include "SPoint.h"

class CRectangle : public CSimpleShape
{
public:
	CRectangle(SPoint leftTop, SPoint rightBottom);

	void Draw(ICanvas & canvas) final;

	virtual RectDouble GetFrame()const final;
	virtual void SetFrame(const RectDouble & rect) final;
private:
	SPoint m_leftTop;
	SPoint m_rightBottom;
	RectDouble m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
};