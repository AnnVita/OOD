#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}
	
	void AddDescription(std::string const& additionalDescription)
	{
		m_description += " ";
		m_description += additionalDescription;
	}

	void SetDescription(std::string const& description)
	{
		m_description = description;
	}

	std::string GetDescription()const override final
	{
		return m_description;
	}

private:
	std::string m_description;
};	