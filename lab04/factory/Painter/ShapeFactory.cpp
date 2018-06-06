#include "stdafx.h"
#include "IShapeFactory.h"
#include "ShapeFactory.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"

using namespace std;

CShapeFactory::CShapeFactory()
{}

unique_ptr<CShape> CShapeFactory::CreateShape(const std::string & description)
{
	vector<string> parameters = GetParamsFromString(description);
	string shape = parameters.at(0);

	if (shape == "triangle")
	{
		return GetTriangleWith(parameters);
	}
	else if (shape == "rectangle")
	{
		return GetRectangleWith(parameters);
	}
	else if (shape == "ellipse")
	{
		return GetEllipseWith(parameters);
	}
	else if (shape == "polygon")
	{
		return GetRegularPolygonWith(parameters);
	}

	throw std::invalid_argument("Unknown shape!");
}

std::unique_ptr<CShape> CShapeFactory::GetTriangleWith(const std::vector<std::string> & params) const
{
	EColor color = GetColorFromString(params.at(1));
	Vertex v1 = { stof(params.at(2)), stof(params.at(3)) };
	Vertex v2 = { stof(params.at(4)), stof(params.at(5)) };
	Vertex v3 = { stof(params.at(6)), stof(params.at(7)) };

	return make_unique<CTriangle>(color, v1, v2, v3);
}

std::unique_ptr<CShape> CShapeFactory::GetRectangleWith(const std::vector<std::string> &params) const
{
	EColor color = GetColorFromString(params.at(1));
	Vertex leftTop = { stof(params.at(2)), stof(params.at(3)) };
	Vertex rightTop = { stof(params.at(4)), stof(params.at(5)) };

	return make_unique<CRectangle>(color, leftTop, rightTop);
}

std::unique_ptr<CShape> CShapeFactory::GetEllipseWith(const std::vector<std::string> &params) const
{
	EColor color = GetColorFromString(params.at(1));
	Vertex center = { stof(params.at(2)), stof(params.at(3)) };
	float width = stof(params.at(4));
	float height = stof(params.at(5));

	return make_unique<CEllipse>(color, center, width, height);
}

std::unique_ptr<CShape> CShapeFactory::GetRegularPolygonWith(const std::vector<std::string> &params) const
{
	EColor color = GetColorFromString(params.at(1));
	Vertex center = { stof(params.at(2)), stof(params.at(3)) };
	float radius = stof(params.at(4));
	int vertexCount = stoi(params.at(5));

	return make_unique<CRegularPolygon>(color, center, radius, vertexCount);
}