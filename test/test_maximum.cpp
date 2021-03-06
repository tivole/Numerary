// test_maximum.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestMaximum)
    
    BOOST_AUTO_TEST_CASE(test_maximum_bisection)
    {
        const double eps = 1.e-9;
        double answer;
        double expected_answer;
        short int result;
        short int expected_result;

        // Testing sin function
        expected_result = 1;
        expected_answer = M_PI_2;
        result = Numerary::maximum(sin, -3, 3, &answer, "bisection", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);

	    // Testing log function
        expected_result = 1;
        expected_answer = 4.0;
        result = Numerary::maximum(log, 0.5, 4, &answer, "bisection", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);
    }


    BOOST_AUTO_TEST_CASE(test_maximum_golden_ratio)
    {
        const double eps = 1.e-9;
        double answer;
        double expected_answer;
        short int result;
        short int expected_result;

        // Testing sin function
        expected_result = 1;
        expected_answer = M_PI_2;
        result = Numerary::maximum(sin, -3, 3, &answer, "golden_ratio", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);

	    // Testing cos function
        expected_result = 1;
        expected_answer = 4.0;
        result = Numerary::maximum(log, 0.5, 4, &answer, "golden_ratio", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);
    }

    BOOST_AUTO_TEST_SUITE_END()
}

