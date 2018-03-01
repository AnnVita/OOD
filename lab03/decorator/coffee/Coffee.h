#pragma once

#include "Beverage.h"

enum ServingSizeOfCoffe
{
	STANDART,
	DOUBLE
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee", ServingSizeOfCoffe size = ServingSizeOfCoffe::STANDART)
		:CBeverage(description),
		m_size(size)
	{
		AddDescription(GetSizeDescription());
	}

	double GetCost() const override
	{
		double additionalPrice = (m_size == ServingSizeOfCoffe::STANDART) ? 0 : 40;
		return 60 + additionalPrice;
	}
protected:
	std::string const GetSizeDescription()
	{
		std::string result;
		if (m_size == ServingSizeOfCoffe::STANDART)
		{
			result = "standart";
		}
		else if (m_size == ServingSizeOfCoffe::DOUBLE)
		{
			result = "double";
		}
		return result;
	}
	ServingSizeOfCoffe m_size;
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(ServingSizeOfCoffe size = ServingSizeOfCoffe::STANDART)
		:CCoffee("Capuccino", size)
	{}

	double GetCost() const override
	{
		double additionalPrice = (m_size == ServingSizeOfCoffe::STANDART) ? 0 : 40;
		return 80 + additionalPrice;
	}
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(ServingSizeOfCoffe size = ServingSizeOfCoffe::STANDART)
		:CCoffee("Latte", size)
	{}

	double GetCost() const override
	{
		double additionalPrice = (m_size == ServingSizeOfCoffe::STANDART) ? 0 : 40;
		return 90 + additionalPrice;
	}
};