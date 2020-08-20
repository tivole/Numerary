// interpolation.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{

    double Numerary::lagrange_polynomial(double *X, double *Y, const double& x, const int& n) {
        double multiplication, result = 0;
      
        for (int i = 0; i < n; i++) {
            multiplication = Y[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    multiplication *= (x - X[j]) / (X[i] - X[j]);
            }
            result += multiplication;
        }
      
        return result; 
    }

}
