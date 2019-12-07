// (c) Tivole

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


#define N 11
#define VISUALIZE false


double *linear_regression(double*, double*, int);


int main() {

    double a, b;

    srand(time(NULL));




    return 0;
}


double *linear_regression(double *X, double *Y, int n) {
    int i;
    double E_X = 0, E_Y = 0, E_XY = 0, E_X2 = 0;
    double *ab = new double[2];

    for (i = 0; i < n; i++) {
        E_X     += X[i];
        E_X2    += (X[i]*X[i]);
        E_Y     += Y[i];
        E_XY    += (X[i]*Y[i]);
    }

    ab[1] = (n*E_XY - E_X*E_Y) / (n*E_X2 - E_X*E_X);
    ab[0] = (E_Y - ab[1]*E_X) / ((double) n);
    
    return ab;
}