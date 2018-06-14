#include "stdafx.h"
#include "CommonTypes.h"
#include "SVGCanvas.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Style.h"
#include "GroupShape.h"
#include "Slide.h"

using namespace std;

const int GRAY_COLOR = 0x607d8bFF;
const int LIGHT_GRAY_COLOR = 0xe9ece7FF;
const int YELLOW_COLOR = 0xffeb3bFF;
const int ORANGE_COLOR = 0xff9800FF;
const int RED_COLOR = 0xff5722FF;

int main()
{
	string canvasFileName = "canvas.svg";

	try
	{
		ofstream canvasFile(canvasFileName);
		if (!canvasFile.is_open())
		{
			throw runtime_error("Error while opening file for canvas.");
		}

		CSVGCanvas canvas(canvasFile);
		
		// fire

		auto fireRed = make_shared<CEllipse>(SPoint{ 400, 550 }, 110, 150);
			auto fireRedFillStyle = fireRed->GetFillStyle();
			auto fireRedOutlineStyle = fireRed->GetOutlineStyle();

			fireRedFillStyle->SetColor(RED_COLOR);
			fireRedOutlineStyle->SetColor(RED_COLOR);

			fireRed->Draw(canvas);
		

		auto fireOrange = make_shared<CEllipse>(SPoint{ 400, 530 }, 90, 90);
			auto fireOrangeFillStyle = fireOrange->GetFillStyle();
			auto fireOrangeOutlineStyle = fireOrange->GetOutlineStyle();

			fireOrangeFillStyle->SetColor(ORANGE_COLOR);
			fireOrangeOutlineStyle->SetColor(ORANGE_COLOR);

			fireOrange->Draw(canvas);

		auto fire = make_shared<CEllipse>(SPoint{ 400, 510 }, 50, 50);
			auto fireFillStyle = fire->GetFillStyle();
			auto fireOutlineStyle = fire->GetOutlineStyle();

			fireFillStyle->SetColor(YELLOW_COLOR);
			fireOutlineStyle->SetColor(YELLOW_COLOR);

			fire->Draw(canvas);

		// rocket

		auto headTriangle = make_shared<CTriangle>(SPoint{ 400, 100 }, SPoint{ 320, 200 }, SPoint{ 480, 200 });
			auto headTriangleFillStyle = headTriangle->GetFillStyle();
			auto headTriangleOutlineStyle = headTriangle->GetOutlineStyle();

			headTriangleFillStyle->SetColor(GRAY_COLOR);
			headTriangleOutlineStyle->SetColor(GRAY_COLOR);

			headTriangle->Draw(canvas);

		auto bodyRectangle = make_shared<CRectangle>(SPoint{ 320, 200 }, SPoint{ 480, 500 });
			auto bodyRectangleFillStyle = bodyRectangle->GetFillStyle();
			auto bodyRectangleOutlineStyle = bodyRectangle->GetOutlineStyle();

			bodyRectangleFillStyle->SetColor(LIGHT_GRAY_COLOR);
			bodyRectangleOutlineStyle->SetColor(LIGHT_GRAY_COLOR);

			bodyRectangle->Draw(canvas);

		auto footerRectangle = make_shared<CRectangle>(SPoint{ 320, 500 }, SPoint{ 480, 520 });
			auto footerRectangleFillStyle = footerRectangle->GetFillStyle();
			auto footerRectangleOutlineStyle = footerRectangle->GetOutlineStyle();

			footerRectangleFillStyle->SetColor(GRAY_COLOR);
			footerRectangleOutlineStyle->SetColor(GRAY_COLOR);

			footerRectangle->Draw(canvas);

		auto leftSideTriangle = make_shared<CTriangle>(SPoint{ 320, 500 }, SPoint{ 290, 500 }, SPoint{ 320, 200 });
			auto leftSideTriangleFillStyle = leftSideTriangle->GetFillStyle();
			auto leftSideTriangleOutlineStyle = leftSideTriangle->GetOutlineStyle();

			leftSideTriangleFillStyle->SetColor(GRAY_COLOR);
			leftSideTriangleOutlineStyle->SetColor(GRAY_COLOR);

			leftSideTriangle->Draw(canvas);

		auto rightSideTriangle = make_shared<CTriangle>(SPoint{ 480, 200 }, SPoint{ 510, 500 }, SPoint{ 480, 500 });
			auto rightSideTriangleFillStyle = rightSideTriangle->GetFillStyle();
			auto rightSideTriangleOutlineStyle = rightSideTriangle->GetOutlineStyle();

			rightSideTriangleFillStyle->SetColor(GRAY_COLOR);
			rightSideTriangleOutlineStyle->SetColor(GRAY_COLOR);

			rightSideTriangle->Draw(canvas);

		auto rocket = make_shared<CGroupShape>();
		rocket->InsertShape(fireRed);
		rocket->InsertShape(fireOrange);
		rocket->InsertShape(fire);
		rocket->InsertShape(headTriangle);
		rocket->InsertShape(bodyRectangle);
		rocket->InsertShape(rightSideTriangle);
		rocket->InsertShape(leftSideTriangle);
		rocket->InsertShape(footerRectangle);
		rocket->SetFrame({ 480, 100, 500, 800 });

		CSlide slide;
		slide.InsertShape(rocket);
		slide.Draw(canvas);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
