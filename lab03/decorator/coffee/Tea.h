#pragma once

#include "Beverage.h"

enum TeaType
{
	BLACK,
	GREEN,
	RED,
	WHITE
};

// ×àé
class CTea : public CBeverage
{
public:
	CTea(TeaType type = TeaType::BLACK)
		:CBeverage("Tea"),
		m_type(type)
	{
		AddDescription(GetTeaTypeDescription());
	}

	double GetCost() const override
	{
		return 30;
	}
protected:
	std::string const GetTeaTypeDescription()
	{
		std::string result;
		if (m_type == TeaType::BLACK)
		{
			result = "black";
		}
		else if (m_type == TeaType::GREEN)
		{
			result = "green";
		}
		else if (m_type == TeaType::RED)
		{
			result = "red";
		}
		else if (m_type == TeaType::WHITE)
		{
			result = "white";
		}
		return result;
	}

	TeaType m_type;
};