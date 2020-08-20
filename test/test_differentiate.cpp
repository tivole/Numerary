// test_differentiate.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestDifferentiate)
    
    BOOST_AUTO_TEST_CASE(test_differentiate_order_1_h)
    {
        const double h = 0.00001;
        const short int order = 1;
        double x;
        double expected_result;
        double result;

        // Testing sin
        x = M_PI;
        expected_result = -1;
        result = Numerary::differentiate(sin, 1, x, "h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);


        // Testing cos
        x = M_PI_2;
        expected_result = -1;
        result = Numerary::differentiate(cos, 1, x, "h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);

        // Testing exp
        x = 1;
        expected_result = 2.718281828;
        result = Numerary::differentiate(exp, 1, x, "h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);
    }


    BOOST_AUTO_TEST_CASE(test_differentiate_order_1_2h)
    {
        const double h = 0.00001;
        const short int order = 1;
        double x;
        double expected_result;
        double result;

        // Testing sin
        x = M_PI;
        expected_result = -1;
        result = Numerary::differentiate(sin, 1, x, "2h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);


        // Testing cos
        x = M_PI_2;
        expected_result = -1;
        result = Numerary::differentiate(cos, 1, x, "2h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);

        // Testing exp
        x = 1;
        expected_result = 2.718281828;
        result = Numerary::differentiate(exp, 1, x, "2h", h);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-4);
    }

    BOOST_AUTO_TEST_SUITE_END()
}

