#include "stdafx.h"
#include "Shape.h"

CShape::CShape()
{}

void CShape::SetColor(EColor color)
{
	m_color = color;
}

EColor CShape::GetColor() const
{
	return m_color;
}

