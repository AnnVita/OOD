#include "stdafx.h"
#include "Painter.h"
#include "PictureDraft.h"
#include "IShapeFactory.h"
#include "ShapeFactory.h"
#include "Designer.h"
#include "Canvas.h"

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);

	CCanvas canvas(std::cout);
	CPainter painter;
	/*
	unique_ptr<CShape> rectangle = shapeFactory.CreateShape("rectangle blue 70 70 200 200");
	rectangle->Draw(canvas);

	unique_ptr<CShape> triangle = shapeFactory.CreateShape("triangle red 70 70 200 200 100 100");
	triangle->Draw(canvas);

	unique_ptr<CShape> ellipse = shapeFactory.CreateShape("ellipse pink 300 300 200 100");
	ellipse->Draw(canvas);

	unique_ptr<CShape> regularPolygon = shapeFactory.CreateShape("polygon pink 300 300 400 7");
	regularPolygon->Draw(canvas);
	*/

	painter.DrawPicture(designer.CreateDraft(std::cin), canvas);

	return 0;
}

