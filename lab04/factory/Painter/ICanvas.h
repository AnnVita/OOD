#pragma once
#include "stdafx.h"
#include "EColor.h"

class ICanvas
{
public:
	virtual void SetColor(EColor color) = 0;
	virtual void DrawLine(const Vertex from, const Vertex to) = 0;
	virtual void DrawEllipse(const Vertex center, float width, float height) = 0;
	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual ~ICanvas() = default;
};