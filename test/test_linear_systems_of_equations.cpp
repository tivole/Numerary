// test_linear_systems_of_equations.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestLinearSystemsOfEquations)

    BOOST_AUTO_TEST_CASE(test_gauss_elimination)
    {
        double **a = new double*[3];
        double *y = new double[3];
        double *x = new double[3];
        double *expected_x = new double[3];
        short int result;

        for (int i = 0; i < 3; i ++)
            a[i] = new double[3];

        expected_x[0] = 5.0/2.0;
        expected_x[1] = 2.0/3.0;
        expected_x[2] = 2.0/9.0;

        a[0][0] = 2;
        a[0][1] = -1;
        a[0][2] = 3;

        a[1][0] = 2;
        a[1][1] = 2;
        a[1][2] = 3;

        a[2][0] = -2;
        a[2][1] = 3;
        a[2][2] = 0;

        y[0] = 5;
        y[1] = 7;
        y[2] = -3;

        result = Numerary::linear_systems_of_equations(a, y, x, 3, "gauss");

        for (int i = 0; i < 3; i ++) BOOST_CHECK(fabs(expected_x[i] - x[i]) < 1.e-7);

        for (int i = 0; i < 3; i++) delete[] a[i];

        delete[] a;
        delete[] x;
        delete[] y;
        delete[] expected_x;
        
    }

    BOOST_AUTO_TEST_SUITE_END()
}

