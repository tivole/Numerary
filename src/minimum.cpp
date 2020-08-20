// minimum.cpp
// (c) Tivole


// Numerary includes
#include "numerary.hpp"

namespace numerary
{

    short int Numerary::minimum_bisection(double (*f)(double), double a, double b, double *minimum, const double& eps)
    {
        
        double c = (a + b)/2, fc = f(c), fa = f(a), fb = f(b), d1, d2, fd1, fd2;

        // Check is method allowed or not.
        if ((fa <= fc) && (fb <= fc)) return 0;
        
        while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
            d1 = (a + c)/2;
            d2 = (c + b)/2;

            fd1 = f(d1);
            fd2 = f(d2);
            
            if ((fd1 <= fc) && (fd1 <= fd2)) {
                b = c;
                fb = fc;
                c = d1;
                fc = fd1;
            } else if ((fc <= fd1) && (fc <= fd2)) {
                a = d1;
                fa = fd1;
                b = d2;
                fb = fd2;
            } else if ((fd2 <= fc) && (fd2 <= fd1)) {
                a = c;
                c = d2;
                fa = fc;
                fc = fd2;
            }
        }

        *minimum = c;
        
        return 1;
    }



    short int Numerary::minimum_golden_ratio(double (*f)(double), double a, double b, double *minimum, const double& eps)
    {
        double x1, x2, fx1, fx2;
        const double phi = 1.618033988749894848204586834365;
        
        x1 = b - (b - a) / phi; 
        x2 = a + (b - a) / phi;
        fx1 = f(x1);
        fx2 = f(x2);

        while (fabs(b - a) > eps) {
            if (fx1 >= fx2) {
                a = x1;
                x1 = x2;
                fx1 = fx2;
                x2 = a + (b - a) / phi;
                fx2 = f(x2);
            } else {
                b = x2;
                x2 = x1;
                fx2 = fx1;
                x1 = b - (b - a) / phi; 
                fx1 = f(x1);
            }
        }

        *minimum = (a + b) / 2.0;

        return 1;
    }



    short int Numerary::minimum(double (*f)(double), double a, double b, double* minimum, const std::string& method, const double& eps)
    {
        if (method == "bisection") return minimum_bisection(f, a, b, minimum, eps);
        if (method == "golden_ratio") return minimum_golden_ratio(f, a, b, minimum, eps);

        std::cerr << "Error - method \"" << method << "\" doesn't exist!";
        assert(false);

        return 2;
    }

}
