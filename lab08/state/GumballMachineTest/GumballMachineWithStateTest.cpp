#include "stdafx.h"
#include "../GumballMachine/GumBallMachineWithState.h"

using namespace std;

struct Gumball_machine_with_state_
{
	stringstream outputStream;
	with_state::CGumballMachine machine{ 5 };
};

BOOST_FIXTURE_TEST_SUITE(Gumball_machine_with_state, Gumball_machine_with_state_)
	BOOST_AUTO_TEST_SUITE(after_creation)
	
	BOOST_AUTO_TEST_CASE(cant_eject_quarter)
	{
		string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for quarter
)";

		machine.EjectQuarter();
		BOOST_CHECK_EQUAL(outputStream.str(), "");
		BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
	}

		BOOST_AUTO_TEST_CASE(has_correct_init_state)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for quarter
)";

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(change_state_to_sold_out_if_we_sell_all_gumballs)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 4 gumballs
Machine is waiting for quarter
)";

			machine.InsertQuarter();
			machine.TurnCrank();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());

			expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());

			expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 2 gumballs
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());

			expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 1 gumball
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());


			expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 0 gumballs
Machine is sold out
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}

		BOOST_AUTO_TEST_CASE(does_not_change_state_if_we_turn_crank)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for quarter
)";

			machine.TurnCrank();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}

		BOOST_AUTO_TEST_CASE(change_state_only_after_inserting_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for turn of crank
)";

			machine.InsertQuarter();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}

		BOOST_AUTO_TEST_CASE(reduces_balls_count_and_change_state_if_we_turn_crank)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 4 gumballs
Machine is waiting for quarter
)";

			machine.InsertQuarter();
			machine.TurnCrank();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}

		BOOST_AUTO_TEST_CASE(does_not_change_state_if_user_will_ejet_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.EjectQuarter();
			machine.TurnCrank();

			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}

		BOOST_AUTO_TEST_CASE(waiting_for_turn_of_crank_after_repeated_insertion_of_a_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 5 gumballs
Machine is waiting for turn of crank
)";
			machine.InsertQuarter();
			machine.InsertQuarter();
			BOOST_CHECK_EQUAL(expectedOutput, machine.ToString());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()