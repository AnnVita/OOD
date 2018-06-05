#pragma once
#include "stdafx.h"
#include "ShapeDrawingLib.h"

namespace shape_drawing_lib
{
	CTriangle::CTriangle(const Point & p1, const Point & p2, const Point & p3, uint32_t color)
		: m_pFirst(p1)
		, m_pSecond(p2)
		, m_pThird(p3)
		, m_color(color)
	{
	}

	void CTriangle::Draw(graphics_lib::ICanvas & canvas)const
	{
		canvas.SetColor(m_color);
		canvas.MoveTo(m_pFirst.x, m_pFirst.y);
		canvas.LineTo(m_pSecond.x, m_pSecond.y);
		canvas.LineTo(m_pThird.x, m_pThird.y);
		canvas.LineTo(m_pFirst.x, m_pFirst.y);
	}

	CRectangle::CRectangle(const Point & leftTop, int width, int height, uint32_t color)
	{
		m_leftTop = leftTop;
		m_rightBottom = { leftTop.x + width, leftTop.y + height };
		m_color = color;
	}

	void CRectangle::Draw(graphics_lib::ICanvas & canvas)const
	{
		canvas.SetColor(m_color);
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_rightBottom.x, m_leftTop.y);
		canvas.LineTo(m_rightBottom.x, m_rightBottom.y);
		canvas.LineTo(m_leftTop.x, m_rightBottom.y);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);
	}

	CCanvasPainter::CCanvasPainter(graphics_lib::ICanvas & canvas)
		: m_canvas(&canvas)
	{
	}

	void CCanvasPainter::Draw(const ICanvasDrawable & drawable)
	{
		drawable.Draw(*m_canvas);
	}
}