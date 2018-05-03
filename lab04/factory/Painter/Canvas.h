#pragma once
#include "ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & outputStream)
		: m_output(outputStream)
	{};

	void SetColor(EColor color) override;
	void DrawLine(const Vertex from, const Vertex to) override;
	void DrawEllipse(const Vertex center, float width, float height) override;
	void BeginDraw() override;
	void EndDraw() override;
private:
	EColor m_color = EColor::BLUE;
	std::string m_canvasContent;
	std::ostream & m_output;
};