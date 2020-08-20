// test_newton.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestNewton)


    void test_newton_function_1(double *x, double *fv, int n) {
        fv[0] = x[0]*x[0] + x[1]*x[1] - 5;
        fv[1] = x[1] - 3*x[0] + 5;
    }

    void test_newton_function_2(double *x, double *fv, int n) {
        fv[0] = pow(x[0], 5) + pow(x[1], 3) * pow(x[2], 4) + 1;
        fv[1] = x[0]*x[0]*x[1]*x[2];
        fv[2] = pow(x[2], 4) - 1;
    }
    

    BOOST_AUTO_TEST_CASE(test_newton_1)
    {
        const int maxiter = 100;
        int result, expected_result;
        const double eps = 1.e-7;
        double *x = new double[2], *fv = new double[2];
        bool is_passed = false;
        expected_result = 1;
        x[0] = 1; x[1] = 2;

        result = Numerary::nonlinear_systems_of_equations(test_newton_function_1, x, fv, 2, "newton", eps, maxiter);
        BOOST_CHECK_EQUAL(result, expected_result);

        if ((fabs(x[0] - 1) < 1.e-5) && (fabs(x[1] + 2) < 1.e-5)) is_passed = true;
        if ((fabs(x[0] - 2) < 1.e-5) && (fabs(x[1] - 1) < 1.e-5)) is_passed = true;

        BOOST_CHECK(is_passed);

        delete[] x;
        delete[] fv;
    }


    BOOST_AUTO_TEST_CASE(test_newton_2)
    {
        const int maxiter = 100;
        int result, expected_result;
        const double eps = 1.e-7;
        double *x = new double[3], *fv = new double[3];
        bool is_passed = false;
        expected_result = 1;
        x[0] = 1; x[1] = 2, x[2] = -1;

        result = Numerary::nonlinear_systems_of_equations(test_newton_function_2, x, fv, 3, "newton", eps, maxiter);
        BOOST_CHECK_EQUAL(result, expected_result);

        if ((fabs(x[0] + 1) < 1.e-4) && (fabs(x[1]) < 1.e-4) && (fabs(x[2] + 1) < 1.e-4)) is_passed = true;
        if ((fabs(x[0] + 1) < 1.e-4) && (fabs(x[1]) < 1.e-4) && (fabs(x[2] - 1) < 1.e-4)) is_passed = true;
        if ((fabs(x[0]) < 1.e-4) && (fabs(x[1] + 1) < 1.e-4) && (fabs(x[2] + 1) < 1.e-4)) is_passed = true;
        if ((fabs(x[0]) < 1.e-4) && (fabs(x[1] + 1) < 1.e-4) && (fabs(x[2] - 1) < 1.e-4)) is_passed = true;

        BOOST_CHECK(is_passed);

        delete[] x;
        delete[] fv;
    }

    BOOST_AUTO_TEST_SUITE_END()
}

