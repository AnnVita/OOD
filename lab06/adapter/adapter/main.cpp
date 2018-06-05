#include "stdafx.h"
#include "GraphicsLib.h"
#include "ShapeDrawingLib.h"
#include "ModernGraphicsLib.h"
#include "Application.h"

using namespace std;
const bool WILL_USE_CLASS_ADAPTER = false;

int main()
{
	cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		if (WILL_USE_CLASS_ADAPTER)
		{
			app::PaintPictureOnModernGraphicsRendererWithClassAdapter(cout);
		}
		else
		{
			app::PaintPictureOnModernGraphicsRenderer(cout);
		}
	}
	else
	{
		app::PaintPictureOnCanvas(cout);
	}

	return 0;
}
