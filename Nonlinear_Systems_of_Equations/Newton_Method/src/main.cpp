// main.cpp

#include <math.h>
#include <iostream>
#include "NSE.cpp"
using namespace std;

#define N 2
#define eps 1e-7

// Function with Nonlinear Systems of Equations
void f(double *x, double *fv, int n) {
    fv[0] = x[0]*x[0] + x[1]*x[1] - 5;
    fv[1] = x[1] - 3*x[0] + 5;
}

int main() {
    // Variable initialization
    double *x = new double[N], *fv = new double[N];
    int maxiter = 100;

    // Initial point
    x[0] = 1; x[1] = 2;

    // Newton's Method for Nonlinear Systems of Equations
    NSE(f, x, fv, N, eps, &maxiter);

    // Results:
    cout << "X:\n";
    for (int i = 0; i < N; i++) cout << "x[" << i << "] = " << x[i] << endl;
    cout << "\nFv:\n";
    for (int i = 0; i < N; i++) cout << "Fv[" << i << "] = " << fv[i] << endl;
    cout << "\nNumber of iterations = " << maxiter << "\n";

    return 0;
}