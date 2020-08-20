// test_lagrange_polynomial.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestLagrangePolynomial)


    double test_lagrange_polynomial_function_1(double x) {
        return sin(x);
    }


    BOOST_AUTO_TEST_CASE(test_lagrange_polynomial)
    {
        const int N = 11;
        const int TEST_N = 51;
        int i;
        double a, b, step, x, min_y, max_y;
        double *X = new double[N], *Y = new double[N], *TEST_X = new double[TEST_N], *TEST_Y = new double[TEST_N];

        // The main segment
        a = -5;
        b = 5;


        // Calculating values of function in N points for using future in LP.
        step = (b - a) / double(N - 1);
        x = a;
        min_y = test_lagrange_polynomial_function_1(a);
        max_y = test_lagrange_polynomial_function_1(a);
        for (i = 0; i < N; i++, x += step) {
            X[i] = x;
            Y[i] = test_lagrange_polynomial_function_1(X[i]);

            if (min_y > Y[i]) min_y = Y[i];
            if (max_y < Y[i]) max_y = Y[i];
        }

        // Calculating values of LP in TEST_N points
        step = (b - a) / double(TEST_N - 1);
        x = a;
        for (i = 0; i < TEST_N; i++, x += step) {
            TEST_X[i] = x;
            TEST_Y[i] = Numerary::lagrange_polynomial(X, Y, TEST_X[i], N);
        }


        // Calculating norm_1, norm_2, norm_3
        double norm_1, norm_2, norm_3;
        norm_1 = abs(TEST_Y[0] - test_lagrange_polynomial_function_1(TEST_X[0])); // max abs
        norm_2 = abs(TEST_Y[0] - test_lagrange_polynomial_function_1(TEST_X[0])); // sum abs
        norm_3 = (TEST_Y[0] - test_lagrange_polynomial_function_1(TEST_X[0]))*(TEST_Y[0] - test_lagrange_polynomial_function_1(TEST_X[0])); // sqrt of sum of sqr

        for (i = 1; i < TEST_N; i ++) {
            x = abs(TEST_Y[i] - test_lagrange_polynomial_function_1(TEST_X[i]));
            if (x > norm_1) norm_1 = x;
            norm_2 += x;
            norm_3 += (x*x);
        }
        norm_3 = sqrt(norm_3);

        BOOST_CHECK(norm_1 < 1.e-2);
        BOOST_CHECK(norm_2 < 1.e-1);
        BOOST_CHECK(norm_3 < 1.e-1);

        delete[] X;
        delete[] Y;
        delete[] TEST_X;
        delete[] TEST_Y;
    }

    BOOST_AUTO_TEST_SUITE_END()
}

