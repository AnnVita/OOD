#pragma once
#include "IStyle.h"
#include "Shapes.h"
#include "IGetStyleBehavior.h"

class CCompositeStyle : public IStyle
{
public:
	CCompositeStyle(std::shared_ptr<const CShapes> shapes, std::unique_ptr<IGetStyleBehavior> style)
		: m_shapes(move(shapes))
		, m_style(move(style))
	{}

	virtual optional<bool> IsEnabled()const override;
	virtual void Enable(bool enable) override;

	virtual optional<RGBAColor> GetColor()const override;
	virtual void SetColor(RGBAColor color) override;

private:
	std::shared_ptr<const IShapes> m_shapes;
	std::unique_ptr<IGetStyleBehavior> m_style;
};