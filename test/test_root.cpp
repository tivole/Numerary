// test_root.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestRootFunctions)
    
    BOOST_AUTO_TEST_CASE(test_root_bisection)
    {
        const double eps = 1.e-9;
        double answer;
        double expected_answer;
        short int result;
        short int expected_result;

        // Testing sin function
        expected_result = 1;
        expected_answer = 0.0f;
        result = Numerary::root(sin, -3, 3, &answer, "bisection", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);

	    // Testing log function
        expected_result = 1;
        expected_answer = 1.0f;
        result = Numerary::root(log, 0, 3, &answer, "bisection", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);
    }


    BOOST_AUTO_TEST_CASE(test_root_secant)
    {
        const double eps = 1.e-9;
        double answer;
        double expected_answer;
        short int result;
        short int expected_result;

        // Testing sin function
        expected_result = 1;
        expected_answer = 0.0f;
        result = Numerary::root(sin, -3, 3, &answer, "secant", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
        BOOST_CHECK(fabs(answer - expected_answer) < 1.e-7);

	    // Testing cos function
        expected_result = 0;
        result = Numerary::root(cos, -3, 3, &answer, "secant", eps);
        BOOST_CHECK_EQUAL(result, expected_result);
    }

    BOOST_AUTO_TEST_SUITE_END()
}

