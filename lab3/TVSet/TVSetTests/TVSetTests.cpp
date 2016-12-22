// TVSetTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../TVSet/TVSet.h"

struct TVSetFixture
{
	CTVSet tvSet;
};

struct TVSetTurnedOnFixture : TVSetFixture
{
	TVSetTurnedOnFixture()
	{
		tvSet.TurnOn();
	}
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!tvSet.IsTurnedOn());
	}

	BOOST_FIXTURE_TEST_SUITE(when_turned_off, TVSetFixture)

		BOOST_AUTO_TEST_CASE(has_zero_channel_number)
		{
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 0);
		}

		BOOST_AUTO_TEST_CASE(can_not_switch_channel)
		{
			BOOST_CHECK(!tvSet.SelectChannel(3));
		}

		BOOST_AUTO_TEST_CASE(can_be_turned_on)
		{
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.IsTurnedOn());
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, TVSetTurnedOnFixture)

		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			tvSet.TurnOff();
			BOOST_CHECK(!tvSet.IsTurnedOn());
		}

		BOOST_AUTO_TEST_CASE(can_select_channel)
		{
			tvSet.SelectChannel(5);
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 5);
		}

		BOOST_AUTO_TEST_CASE(has_started_on_channel_1)
		{
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 1);
		}

		BOOST_AUTO_TEST_CASE(has_channel_range_between_1_and_99)
		{
			BOOST_CHECK(!tvSet.SelectChannel(100));
		}

		BOOST_AUTO_TEST_CASE(on_tv_first_start_can_switch_to_previous_channel_that_has_number_1)
		{
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.SelectPreviousChannel());
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 1);
		}

		BOOST_AUTO_TEST_CASE(on_tv_start_remains_previous_selected_channel)
		{
			tvSet.SelectChannel(17);
			tvSet.TurnOff();
			tvSet.TurnOn();
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 17);
		}

		BOOST_AUTO_TEST_CASE(on_tv_start_can_switch_to_previous_channel)
		{
			tvSet.TurnOn();
			tvSet.SelectChannel(12);
			tvSet.SelectChannel(47);
			tvSet.TurnOff();
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.SelectPreviousChannel());
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 12);
		}

		BOOST_AUTO_TEST_CASE(can_switch_to_previous_channel)
		{
			tvSet.SelectChannel(33);
			tvSet.SelectChannel(62);
			tvSet.SelectPreviousChannel();
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 33);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()