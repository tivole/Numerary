// nonlinear_systems_of_equations.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{

    short int Numerary::nonlinear_systems_of_equations_newton(void (*f)(double *x, double *fv, int n), double *x, double *fv, int n, double eps, int maxiter)
    {
        double tmp, delta, **jacobian, *p, *x0;
        int i, j, k;

        jacobian = new double *[n];
        for (i = 0; i < n; i++)
            jacobian[i] = new double[n];

        p = new double[n];
        x0 = new double[n];

        for (k = 0; k < maxiter; k++)
        {
            f(x, fv, n); // get residuals for current value of 'x'

            // Compute Jacobian matrix
            for (i = 0; i < n; i++)
            {
                tmp = x[i];
                delta = (tmp > 1.0) ? eps * tmp : eps;
                x[i] = tmp + delta; // bump this element
                delta = x[i] - tmp; // try this to reduce error (from Schnabel)
                f(x, p, n);
                x[i] = tmp; // restore original value

                for (j = 0; j < n; j++)
                    jacobian[j][i] = (p[j] - fv[j]) / delta;
            }

            // Update residuals
            for (i = 0; i < n; i++)
            {
                tmp = 0.0;
                for (j = 0; j < n; j++)
                {
                    tmp += jacobian[i][j] * x[j];
                }
                p[i] = tmp - fv[i];
            }

            // Update solution vector
            gauss_elimination(jacobian, p, x0, n); // Gauss Elimination Method

            // Test for convergence
            tmp = 0.0;
            for (i = 0; i < n; i++)
            {
                tmp += fabs(x[i] - x0[i]);
                x[i] = x0[i];
            }

            if (tmp < 1e-4)
                break;
        }

        // Delete temporary storage
        delete[] x0;
        delete[] p;

        for (i = 0; i < n; i++)
            delete[] jacobian[i];

        delete[] jacobian;

        return 1;
    }   



    short int Numerary::nonlinear_systems_of_equations(void (*f)(double *x, double *fv, int n), double *x, double *fv, int n, const std::string& method, double eps, int maxiter)
    {
        if (method == "newton") return nonlinear_systems_of_equations_newton(f, x, fv, n, eps, maxiter);

        std::cerr << "Error - method \"" << method << "\" doesn't exist!";
        assert(false);

        return 2;
    }

}
