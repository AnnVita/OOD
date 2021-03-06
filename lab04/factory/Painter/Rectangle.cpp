#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(EColor color, Vertex leftTop, Vertex rightBottom)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
	SetColor(color);
}

Vertex CRectangle::GetLeftTop() const
{
	return m_leftTop;
}


Vertex CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}


void CRectangle::Draw(ICanvas & canvas) const
{
	Vertex rightTop = { m_rightBottom.x, m_leftTop.y };
	Vertex leftBottom = { m_leftTop.x, m_rightBottom.y };

	canvas.BeginDraw();
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_leftTop, rightTop);
	canvas.DrawLine(rightTop, m_rightBottom);
	canvas.DrawLine(m_rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, m_leftTop);
	canvas.EndDraw();
}
