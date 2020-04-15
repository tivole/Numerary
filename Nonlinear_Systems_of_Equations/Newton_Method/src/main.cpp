// (c) Tivole

#include <math.h>
#include <iostream>
#include "NSE.cpp"

using namespace std;

void f(double *x, double *fv, int n)
{
    fv[0] = 2*x[0]*x[0] + 3*x[1]*x[1] - 30;
    fv[1] = 3*x[0]*x[0] - 2*x[1]*x[1] - 19;
}

int main() {

    double *x = new double[2];
    double *fv = new double[2];
    double eps = 1e-7;
    int maxiter = 100;

    x[0] = 0;
    x[1] = 0;

    NSE(f, x, fv, 2, eps, &maxiter);

    cout << "X:\nx[0] = " << x[0] << "\nx[1] = " << x[1] << "\n\n";
    
    cout << "Fv:\nfv[0] = " << fv[0] << "\nx[1] = " << fv[1] << "\n\n";

    cout << "Number of iterations = " << maxiter << "\n";

    return 0;
}