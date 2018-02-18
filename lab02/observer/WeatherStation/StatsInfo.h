#pragma once
#include <climits>


class CStatsInfo
{
public:
	void Update(double newValue)
	{
		if (newValue < m_minValue)
		{
			m_minValue = newValue;
		}

		if (m_maxValue < newValue)
		{
			m_maxValue = newValue;
		}

		m_accValue += newValue;
		++m_counterValue;
	}

	double GetMinValue()
	{
		return m_minValue;
	}

	double GetMaxValue()
	{
		return m_maxValue;
	}

	double GetAverage()
	{
		return CountAverage();
	}

	void Print()
	{
		std::cout << "Max value " << m_maxValue << std::endl;
		std::cout << "Min value " << m_minValue << std::endl;
		std::cout << "Average value " << CountAverage() << std::endl;
		std::cout << "----------------" << std::endl;
	}

private:
	double CountAverage()
	{
		return (m_counterValue == 0) ? 0 : m_accValue / m_counterValue;
	}

	double m_minValue = std::numeric_limits<double>::infinity();
	double m_maxValue = -std::numeric_limits<double>::infinity();
	double m_accValue = 0.0;
	size_t m_counterValue = 0;
};