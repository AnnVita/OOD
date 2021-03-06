#pragma once
#include "GraphicsLib.h"

// ������������ ���� ���������� ��� ��������� ����� (���������� graphics_lib)
// ��� ���������� ���������� ��� ���������
namespace shape_drawing_lib
{
	struct Point
	{
		int x;
		int y;
	};

	// ��������� ��������, ������� ����� ���� ���������� �� ������ �� graphics_lib
	class ICanvasDrawable
	{
	public:
		virtual void Draw(graphics_lib::ICanvas & canvas)const = 0;
		virtual ~ICanvasDrawable() = default;
	};

	class CTriangle : public ICanvasDrawable
	{
	public:
		CTriangle(const Point & p1, const Point & p2, const Point & p3, uint32_t color = 0);
		void Draw(graphics_lib::ICanvas & canvas)const override;
	private:
		Point m_pFirst = { 0, 0 };
		Point m_pSecond = { 0, 0 };
		Point m_pThird = { 0, 0 };
		uint32_t m_color;
	};

	class CRectangle : public ICanvasDrawable
	{
	public:
		CRectangle(const Point & leftTop, int width, int height, uint32_t color = 0);
		void Draw(graphics_lib::ICanvas & canvas)const override;
	private:
		Point m_leftTop = { 0, 0 };
		Point m_rightBottom = { 0, 0 };
		uint32_t m_color;
	};

	// ��������, ��������� �������� ICanvasDrawable-������� �� ICanvas
	class CCanvasPainter
	{
	public:
		CCanvasPainter(graphics_lib::ICanvas & canvas);
		virtual void Draw	(const ICanvasDrawable & drawable);
	private:
		graphics_lib::ICanvas *m_canvas;
	};
}