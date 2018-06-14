#pragma once
#include "SimpleShape.h"
#include "SPoint.h"

class CTriangle : public CSimpleShape
{
public:
	CTriangle(SPoint one, SPoint two, SPoint three);

	void Draw(ICanvas & canvas) final;

	virtual RectDouble GetFrame()const final;
	virtual void SetFrame(const RectDouble & rect) final;

private:
	SPoint m_one = { 0, 0 };
	SPoint m_two = { 0, 0 };
	SPoint m_three = { 0, 0 };
	RectDouble m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
	void CalculateNewVertexPosition(SPoint & vertex, RectDouble oldFrame, RectDouble newFrame);
};