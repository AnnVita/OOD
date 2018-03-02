#include "stdafx.h"

class CTestSafeNotification : public IObserver<SWeatherInfo>
{
public:
	CTestSafeNotification(std::stringstream& stream)
		: m_stream(stream)
	{
	}

private:
	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo>& observable) override
	{
		m_stream << "|update with remove|";
		observable.RemoveObserver(*this);
	};
	std::stringstream& m_stream;
};

class CTestObserverPriority : public IObserver<SWeatherInfo>
{
public:
	CTestObserverPriority(std::stringstream& strm, size_t priority = 0)
		: m_priority(priority)
		, m_stream(strm)
	{
	}

private:
	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo>& observable) override
	{
		m_stream << m_priority;
	}
	size_t m_priority = 0;
	std::stringstream& m_stream;
};


BOOST_AUTO_TEST_SUITE(Weather_station)

BOOST_AUTO_TEST_CASE(has_safe_notification_of_observers)
{

	{
		CWeatherData wd;
		std::stringstream strm;
		CTestSafeNotification first(strm);
		CTestSafeNotification second(strm);
		wd.RegisterObserver(second);
		wd.RegisterObserver(first);
		wd.NotifyObservers();

		BOOST_CHECK_EQUAL(strm.str(), "|update with remove||update with remove|");

		strm.clear();
		wd.NotifyObservers();
		BOOST_CHECK_EQUAL(strm.str(), "|update with remove||update with remove|");
	}

}

BOOST_AUTO_TEST_CASE(has_observers_with_priority)
{

	{
		CWeatherData wd;

		std::stringstream strm;

		CTestObserverPriority first(strm);
		CTestObserverPriority second(strm);

		wd.RegisterObserver(second);
		wd.RegisterObserver(first);

		wd.NotifyObservers();

		BOOST_CHECK_EQUAL(strm.str(), "00");
	}

	{
		CWeatherData wd;

		std::stringstream strm;

		CTestObserverPriority first(strm);
		CTestObserverPriority second(strm, 5);
		CTestObserverPriority third(strm, 5);
		CTestObserverPriority fourth(strm, 2);

		wd.RegisterObserver(second, 5);
		wd.RegisterObserver(first);
		wd.RegisterObserver(third, 5);
		wd.RegisterObserver(fourth, 2);

		wd.NotifyObservers();

		BOOST_CHECK_EQUAL(strm.str(), "0255");
	}

}

BOOST_AUTO_TEST_SUITE_END()


