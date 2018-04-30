#pragma once

#include "Beverage.h"

enum class ServingSizeOfMilkshake
{
	SMALL,
	MEDIUM,
	LARGE
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ServingSizeOfMilkshake size = ServingSizeOfMilkshake::MEDIUM)
		:CBeverage("Milkshake"),
		m_size(size)
	{
		AddDescription(GetSizeDescription());
	}

	double GetCost() const override
	{
		double result = 60;
		if (m_size == ServingSizeOfMilkshake::SMALL)
		{
			result = 50;
		}
		else if (m_size == ServingSizeOfMilkshake::LARGE)
		{
			result = 80;
		}
		return result;
	}
protected:
	std::string const GetSizeDescription()
	{
		std::string result;
		if (m_size == ServingSizeOfMilkshake::SMALL)
		{
			result = "small";
		}
		else if (m_size == ServingSizeOfMilkshake::MEDIUM)
		{
			result = "medium";
		}
		else if (m_size == ServingSizeOfMilkshake::LARGE)
		{
			result = "large";
		}
		return result;
	}
	ServingSizeOfMilkshake m_size;
};
