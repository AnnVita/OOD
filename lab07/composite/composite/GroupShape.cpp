#include "stdafx.h"
#include "GroupShape.h"
#include "Style.h"
#include "CompositeStyle.h"
#include "GetFillStyle.h"
#include "GetOutlineStyle.h"

using namespace std;

CGroupShape::CGroupShape()
{
	m_shapes = make_shared<CShapes>();
	m_fillStyle = make_shared<CCompositeStyle>(m_shapes, make_unique<CGetFillStyle>());
	m_outlineStyle = make_shared<CCompositeStyle>(m_shapes, make_unique<CGetOutlineStyle>());
}

void CGroupShape::Draw(ICanvas & canvas)
{
	for (size_t i = 0; i < m_shapes->GetShapesCount(); i++)
	{
		auto shape = m_shapes->GetShapeAtIndex(i);
		shape->Draw(canvas);
	}
}

shared_ptr<IStyle> CGroupShape::GetOutlineStyle()const
{
	return m_outlineStyle;
}

shared_ptr<IStyle> CGroupShape::GetFillStyle()const
{
	return m_fillStyle;
}

shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
	return make_shared<CGroupShape>(*this);
}

shared_ptr<const IGroupShape> CGroupShape::GetGroup() const
{
	return make_shared<CGroupShape>(*this);
}

RectDouble CGroupShape::GetFrame()const
{
	RectDouble frame = { 0, 0, 0, 0 };
	
	if (m_shapes->GetShapesCount() != 0)
	{
		RectDouble const &firstFrame = m_shapes->GetShapeAtIndex(0)->GetFrame();

		double minX = firstFrame.left;
		double minY = firstFrame.top;
		double maxX = minX + firstFrame.width;
		double maxY = minY + firstFrame.height;

		if (m_shapes->GetShapesCount() > 0)
		{
			for (size_t i = 1; i < m_shapes->GetShapesCount(); i++)
			{
				auto shape = m_shapes->GetShapeAtIndex(i);

				RectDouble const &frame = shape->GetFrame();
				minX = min(minX, frame.left);
				minY = min(minY, frame.top);
				maxX = max(maxX, frame.left + frame.width);
				maxY = max(maxY, frame.top + frame.height);
			}
		}		

		frame = { minX, minY, maxX - minX, maxY - minY };
	}

	return frame;
}

void CGroupShape::SetFrame(const RectDouble & rect)
{
	RectDouble oldFrame = GetFrame();

	for (size_t i = 0; i < m_shapes->GetShapesCount(); i++)
	{
		auto shape = m_shapes->GetShapeAtIndex(i);

		RectDouble shapeFrame = shape->GetFrame();
		shapeFrame.left = rect.left + (shapeFrame.left - oldFrame.left) / (oldFrame.width / rect.width);
		shapeFrame.top = rect.top + (shapeFrame.top - oldFrame.top) / (oldFrame.height / rect.height);
		shapeFrame.width = shapeFrame.width * (rect.width / oldFrame.width);
		shapeFrame.height = shapeFrame.height * (rect.height / oldFrame.height);
		shape->SetFrame(shapeFrame);
	}
}

size_t CGroupShape::GetShapesCount()const
{
	return m_shapes->GetShapesCount();
}

void CGroupShape::InsertShape(const std::shared_ptr<IShape> & shape)
{
	m_shapes->InsertShape(shape);
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)const
{
	return m_shapes->GetShapeAtIndex(index);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	m_shapes->RemoveShapeAtIndex(index);
}