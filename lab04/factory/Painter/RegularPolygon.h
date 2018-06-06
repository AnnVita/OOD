#pragma once
#include "Shape.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(EColor color, Vertex center, float radius, int vertexCount);
	Vertex GetCenter() const;
	float GetRadius() const;
	int GetVertexCount() const;
	void Draw(ICanvas & canvas) const override;
private:
	std::vector<Vertex> GetVerticies() const;
	Vertex m_center;
	float m_radius;
	int m_vertexCount;
};