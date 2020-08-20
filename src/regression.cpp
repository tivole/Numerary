// regression.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{
    
    double* Numerary::linear_regression(double *X, double *Y, const int& n) {
        int i;
        double E_X = 0, E_Y = 0, E_XY = 0, E_X2 = 0, *ab = new double[2];

        for (i = 0; i < n; i++) {
            E_X     += X[i]; // Mathematical Expectation of X
            E_X2    += (X[i]*X[i]); // Mathematical Expectation of X^2
            E_Y     += Y[i]; // Mathematical Expectation of Y
            E_XY    += (X[i]*Y[i]); // Mathematical Expectation of X*Y
        }

        // Calculating coefficients of line (y = a*x + b)
        ab[0] = (n*E_XY - E_X*E_Y) / (n*E_X2 - E_X*E_X); // a
        ab[1] = (E_Y - ab[0]*E_X) / ((double) n); // b
        
        return ab;
    }

}
