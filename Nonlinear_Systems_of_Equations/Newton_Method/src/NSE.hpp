// (c) Tivole

#include <cmath>

using namespace std;

// Gauss Elimination Method
int GEM(double **a, double *b, double *x, int n);

// Newton's Method for Nonlinear Systems of Equations
void NSE(void (*f)(double *x, double *fv, int n), double *x,
             double *fv, int n, double eps, int *maxiter);