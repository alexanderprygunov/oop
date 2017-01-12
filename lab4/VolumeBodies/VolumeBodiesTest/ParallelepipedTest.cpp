#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../VolumeBodies/Parallelepiped.h"
#include <math.h>


struct Parallelepiped_
{
    const double expectedWidth = 42.8;
    const double expectedHeight = 18.2;
    const double expectedDepth = 10;
    const double expectedDensity = 8.8;
    const double expectedVolume = expectedWidth * expectedHeight * expectedDepth;
    const CParallelepiped parallelepiped;
    Parallelepiped_()
        : parallelepiped(expectedWidth, expectedHeight, expectedDepth, expectedDensity)
    {}
};
// —фера
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
    // €вл€етс€ объемным телом
    BOOST_AUTO_TEST_CASE(is_a_body)
    {
        BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
    }
    // имеет ширину
    BOOST_AUTO_TEST_CASE(has_a_width)
    {
        BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), expectedWidth);
    }
    // имеет высоту
    BOOST_AUTO_TEST_CASE(has_a_height)
    {
        BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
    }
    // имеет глубину
    BOOST_AUTO_TEST_CASE(has_a_depth)
    {
        BOOST_CHECK_EQUAL(parallelepiped.getDepth(), expectedDepth);
    }
    // имеет плотность
    BOOST_AUTO_TEST_CASE(has_a_density)
    {
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetDensity(), expectedDensity);
    }
    // имеет объем
    BOOST_AUTO_TEST_CASE(has_a_volume)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetVolume(), expectedVolume, 1e-7);
    }
    // имеет массу
    BOOST_AUTO_TEST_CASE(has_a_mass)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetMass(), expectedVolume * expectedDensity, 1e-7);
    }
    // имеет строковое представление
    BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
    {
        const auto expectedString = R"(Parallelepiped:
	density = 8.8
	volume = 7789.6
	mass = 68548.48
	width = 42.8
	height = 18.2
	depth = 10
)";
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
    }
	BOOST_AUTO_TEST_CASE(can_handle_negative_values)
	{
		BOOST_REQUIRE_THROW(CParallelepiped(-1, 1, -3, 0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
