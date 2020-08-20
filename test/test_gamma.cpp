// test_gamma.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestGamma)
    
    BOOST_AUTO_TEST_CASE(test_incgamma)
    {
        double a, x;
        double expected_result;
        double result;

        // Testing incgamma(1, 2)
        a = 1, x = 2;
        expected_result = 0.8646647167633873081060005050275155965923;
        result = Numerary::incgamma(a, x);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-7);

        // Testing incgamma(1, 2)
        a = 0.5, x = 0.4;
        expected_result = 1.11470797904950705652130831956257;
        result = Numerary::incgamma(a, x);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-7);

        // Testing incgamma(0.1, 5)
        a = 0.1, x = 5;
        expected_result = 9.512138334209010516867344600771109;
        result = Numerary::incgamma(a, x);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-7);

        // Testing incgamma(7, 3)
        a = 7, x = 3;
        expected_result = 24.1261454223656689777310564590865;
        result = Numerary::incgamma(a, x);
        BOOST_CHECK(fabs(result - expected_result) <= 1.e-7);
    }

    BOOST_AUTO_TEST_SUITE_END()
}

