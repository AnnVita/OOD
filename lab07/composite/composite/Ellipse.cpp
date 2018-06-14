#include "stdafx.h"
#include "Ellipse.h"

CEllipse::CEllipse(SPoint center, double radiusX, double radiusY)
	: m_center(center)
	, m_radiusX(radiusX)
	, m_radiusY(radiusY)
{
	CalculateFrame();
}

void CEllipse::Draw(ICanvas & canvas)
{
	SetCanvasStyles(canvas);
	canvas.DrawEllipse(m_center.x, m_center.y, m_radiusX, m_radiusY);
}

RectDouble CEllipse::GetFrame()const
{
	return m_frame;
}

void CEllipse::SetFrame(const RectDouble & rect)
{
	m_center.x = rect.left + (rect.width / 2);
	m_center.y = rect.top + (rect.height / 2);
	m_radiusX = rect.width / 2;
	m_radiusY = rect.height / 2;

	CalculateFrame();
}

void CEllipse::CalculateFrame()
{
	m_frame = { m_center.x - m_radiusX , m_center.y - m_radiusY, m_radiusX * 2, m_radiusY * 2 };
}