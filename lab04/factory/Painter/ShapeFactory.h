#pragma once

#include "stdafx.h"
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();
	std::unique_ptr<CShape> CreateShape(const std::string & description) override;
private:
	std::unique_ptr<CShape> GetTriangleWith(const std::vector<std::string> & params) const;
	std::unique_ptr<CShape> GetRectangleWith(const std::vector<std::string> & params) const;
	std::unique_ptr<CShape> GetEllipseWith(const std::vector<std::string> & params) const;
	std::unique_ptr<CShape> GetRegularPolygonWith(const std::vector<std::string> & params) const;
};