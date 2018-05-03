#include "stdafx.h"
#include "Painter.h"

CPainter::CPainter()
{}

void CPainter::DrawPicture(CPictureDraft & draft, ICanvas & canvas)
{
	for (auto it = draft.begin(); it != draft.end(); ++it)
	{
		it->Draw(canvas);
	}
}

CPainter::~CPainter()
{}