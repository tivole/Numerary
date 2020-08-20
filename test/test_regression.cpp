// test_regression.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestRegression)


    double get_rand(double min_val, double max_val) {
        /*
            Returns random double value from interval [min_val, max_val]
        */
        return (max_val - min_val) * ( (double)rand() / (double)RAND_MAX ) + min_val;
    }


    BOOST_AUTO_TEST_CASE(test_linear_regression)
    {
        const int N = 101;
        const double eps = 1.e-2;
        int i;
        double a, b, k, c, step, x, *X = new double[N], *Y = new double[N], *predicted_kc = new double[2];
        
        k = -3;    
        c = 2;
        
        // segment [a, b]
        a = 0;
        b = 1;

        // Generating random values for regression
        step = (b - a) / double(N - 1);
        for (i = 0; i < N; i++, x += step) {
            X[i] = rand() % 2 == 0 ? x + eps: x - eps;
            Y[i] = rand() % 2 == 0 ? (k * X[i] + c) + eps * get_rand(1, 3) : (k * X[i] + c) - eps * get_rand(1, 3);
        }

        // Get predicted linear regression line
        predicted_kc = Numerary::linear_regression(X, Y, N);

        
        BOOST_CHECK(fabs(predicted_kc[0] - k) < 1.e-3);
        BOOST_CHECK(fabs(predicted_kc[1] - c) < 1.e-3);

        delete[] X;
        delete[] Y;
        delete[] predicted_kc;
    }

    BOOST_AUTO_TEST_SUITE_END()
}

