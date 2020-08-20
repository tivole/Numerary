// test_dorpi.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestDorpi)


    double test_dorpi_function_1(double x, double y) {
        return 3.0*y/x + x*x*x + x;
    }


    BOOST_AUTO_TEST_CASE(test_dorpi)
    {
        double *y = new double[2];
        double x0, x, h, expected_answer;
        short int expected_result, result;

        // Initial points
        x0 = 1; y[0] = 3;

        x = 2.0;

        expected_result = 0;
        expected_answer = 36;
        result = Numerary::ordinary_differential_equations(test_dorpi_function_1, y, x0, h, x, "dorpi_4_5");
        BOOST_CHECK_EQUAL(result, expected_result);

        BOOST_CHECK(fabs(expected_answer - y[1]) < 1.e-4);

        delete[] y;
    }

    BOOST_AUTO_TEST_SUITE_END()
}

