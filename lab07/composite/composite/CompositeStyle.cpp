#include "stdafx.h"
#include "CompositeStyle.h"
#include "Style.h"

using namespace std;

void CCompositeStyle::Enable(bool enable)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		for (size_t i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			auto style = m_style->GetStyle(shape);
			style->Enable(true);
		}
	}
}

void CCompositeStyle::SetColor(RGBAColor color)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		for (size_t i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			auto style = m_style->GetStyle(shape);
			style->SetColor(color);
		}
	}
}

optional<bool> CCompositeStyle::IsEnabled()const
{
	optional<bool> isEnabled;

	if (m_shapes->GetShapesCount() == 1)
	{
		auto shape = m_shapes->GetShapeAtIndex(0);
		auto style = m_style->GetStyle(shape);
		return style->IsEnabled();
	}

	if (m_shapes->GetShapesCount() > 1)
	{
		auto firstShape = m_shapes->GetShapeAtIndex(0);
		auto firstStyle = m_style->GetStyle(firstShape);

		isEnabled = firstStyle->IsEnabled();
		for (size_t i = 1; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			auto style = m_style->GetStyle(shape);
			if (style->IsEnabled() != isEnabled)
			{
				isEnabled = boost::none;
				break;
			}
		}
	}

	return isEnabled;
}

optional<RGBAColor> CCompositeStyle::GetColor()const
{
	optional<RGBAColor> resultColor;

	if (m_shapes->GetShapesCount() == 1)
	{
		auto style = m_style->GetStyle(m_shapes->GetShapeAtIndex(0));
		if (style->IsEnabled())
		{
			return style->GetColor();
		}
	}

	if (m_shapes->GetShapesCount() > 1)
	{
		auto firstShape = m_shapes->GetShapeAtIndex(0);
		auto firstStyle = m_style->GetStyle(firstShape);

		if (firstStyle->IsEnabled())
		{
			resultColor = firstStyle->GetColor();
			for (size_t i = 1; i < m_shapes->GetShapesCount(); i++)
			{
				auto shape = m_shapes->GetShapeAtIndex(i);
				auto style = m_style->GetStyle(shape);

				if (style->GetColor() != resultColor || !style->IsEnabled())
				{					
					resultColor = boost::none;
					break;
				}
			}
		}
	}

	return resultColor;
}