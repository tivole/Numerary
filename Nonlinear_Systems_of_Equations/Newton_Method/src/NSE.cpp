// (c) Tivole

#include <cmath>
#include "NSE.hpp"

using namespace std;

// Gauss Elimination Method
int GEM(double **a, double *b, double *x, int n) {
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

            tmp = b[j]; // ...and result vector
            b[j] = b[i];
            b[i] = tmp;
        }

        // (virtual) Gaussian elimination of column
        for (k = i + 1; k < n; k++) {
            tmp = a[k][i] / pvt;
            for (j = i + 1; j < n; j++)
                a[k][j] -= tmp * a[i][j];

            b[k] -= tmp * b[i];
        }
    }

    // Do back substitution
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = n - 1; j > i; j--)
            x[i] -= a[i][j] * x[j];

        x[i] /= a[i][i];
    }
    return 0;
}


// Newton's Method for Nonlinear Systems of Equations
void NSE(void (*f)(double *x, double *fv, int n), double *x,
             double *fv, int n, double eps, int *maxiter)
{
    double tmp, delta, **jac, *p, *x0;
    int i, j, k;

    jac = new double *[n];
    for (i = 0; i < n; i++)
        jac[i] = new double[n];

    p = new double[n];
    x0 = new double[n];

    for (k = 0; k < *maxiter; k++) {
        f(x, fv, n); // get residuals for current value of 'x'

        // Compute Jacobian matrix
        for (i = 0; i < n; i++) {
            tmp = x[i];
            delta = (tmp > 1.0) ? eps * tmp : eps;
            x[i] = tmp + delta; // bump this element
            delta = x[i] - tmp; // try this to reduce error (from Schnabel)
            f(x, p, n);
            x[i] = tmp; // restore original value

            for (j = 0; j < n; j++)
                jac[j][i] = (p[j] - fv[j]) / delta;
        }

        // Update residuals
        for (i = 0; i < n; i++) {
            tmp = 0.0;
            for (j = 0; j < n; j++)
                tmp += jac[i][j] * x[j];
            
            p[i] = tmp - fv[i];
        }

        // Update solution vector
        GEM(jac, p, x0, n); // Gauss Elimination Method

        // Test for convergence
        tmp = 0.0;
        for (i = 0; i < n; i++) {
            tmp += fabs(x[i] - x0[i]);
            x[i] = x0[i];
        }

        if (tmp < 1e-4)
            break;
    }

    *maxiter = k;
    
    // Delete temporary storage
    delete[] x0;
    delete[] p;

    for (i = 0; i < n; i++)
        delete[] jac[i];
    
    delete[] jac;
}
