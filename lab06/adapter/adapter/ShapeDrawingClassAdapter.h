#pragma once
#include "GraphicsLib.h"
#include "ShapeDrawingLib.h"
#include "ModernGraphicsLib.h"

class CShapeDrawingClassAdapter : public graphics_lib::ICanvas, 
	private modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CShapeDrawingClassAdapter(std::ostream & outputStream);
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
	void SetColor(uint32_t rgbColor) override;
	using modern_graphics_lib::CModernGraphicsRenderer::BeginDraw;
	using modern_graphics_lib::CModernGraphicsRenderer::EndDraw;
private:
	modern_graphics_lib::CPoint m_currentPoint = { 0, 0 };
	modern_graphics_lib::CColorRGBA m_color = modern_graphics_lib::CColorRGBA(0, 0, 0, 1);
};

