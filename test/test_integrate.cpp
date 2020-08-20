// test_integrate.cpp
// (c) Tivole

#include <boost/test/unit_test.hpp>
#include "../src/numerary.hpp"

namespace numerary
{
    
    BOOST_AUTO_TEST_SUITE(TestIntegrate)
    
    double test_integrate_function_1(double x) {
        return 5*pow(x, 3) + 2*cos(x);
    }

    double test_integrate_function_2(double x) {
        return (cos(x) / (1.0 + exp(1.0 / x)));
    }

    BOOST_AUTO_TEST_CASE(test_integrate_simpson)
    {
        const double eps = 1e-9;
        double *I = NULL;
        double a, b;
        double expected_result;

        // Testing \int_{0}^{1}\left(\5x^3 + 2cos(x)\right) dx
        a = 0.0;
        b = 1.0;
        expected_result = 2.93294196961579301330500464;
        I = Numerary::integrate(test_integrate_function_1, a, b, "simpson", eps);
        BOOST_CHECK(fabs(I[0] - expected_result) <= I[1]);


        // Testing \int_{-1}^{1} \left( \frac{\cos x}{1 +e^{\frac{1}{x}}} \right)
        a = -1.0;
        b = 1.0;
        expected_result = 0.8414709848078965066525023;
        I = Numerary::integrate(test_integrate_function_2, a, b, "simpson", eps);
        BOOST_CHECK(fabs(I[0] - expected_result) <= I[1]);

        delete[] I;
    }

    BOOST_AUTO_TEST_SUITE_END()
}

