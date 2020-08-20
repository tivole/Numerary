// linear_systems_of_equations.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{
    
    short int Numerary::gauss_elimination(double** a, double* y, double* x, const int& n)
    {
        double tmp, pvt, *t;
        int i, j, k;

        // outer loop on rows
        for (i = 0; i < n; i++) {
            pvt = a[i][i]; // get pivot value
            if (!pvt) {
                for (j = i + 1; j < n; j++) {
                    if ((pvt = a[j][i]) < 1e-9)
                        break;
                }

                if (!pvt)
                    return 1; // nowhere to run!

                t = a[j]; // swap matrix rows...
                a[j] = a[i];
                a[i] = t;

                tmp = y[j]; // ...and result vector
                y[j] = y[i];
                y[i] = tmp;
            }

            // (virtual) Gaussian elimination of column
            for (k = i + 1; k < n; k++) {
                tmp = a[k][i] / pvt;
                for (j = i + 1; j < n; j++)
                    a[k][j] -= tmp * a[i][j];

                y[k] -= tmp * y[i];
            }
        }

        // Do back substitution
        for (i = n - 1; i >= 0; i--) {
            x[i] = y[i];
            for (j = n - 1; j > i; j--)
                x[i] -= a[i][j] * x[j];

            x[i] /= a[i][i];
        }

        return 1;
    }



    short int Numerary::linear_systems_of_equations(double** a, double* y, double* x, const int& n, const std::string& method)
    {
       if (method == "gauss") return gauss_elimination(a, y, x, n);

        std::cerr << "Error - method \"" << method << "\" doesn't exist!";
        assert(false);

       return 2;
    }

}
