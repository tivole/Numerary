// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define N 101


double f(double);
double LP(double*, double*, double, int);


int main()  {

    int i;
    double a, b, step, x;
    double *X = new double[N], *Y = new double[N];

    a = -M_PI / 2.0;
    b = M_PI / 2.0;

    step = (b - a) / double(N - 1);

    for (i = 0; i < N; i++, a+=step) {
        X[i] = a;
        Y[i] = f(X[i]);
    }

    x = M_PI / 4.0;

    cout << "LP = " << LP(X, Y, x, N) << endl;
    cout << "f(x) = " << f(x) << endl;

    // TODO: visualisation with gnuplot and test with N*10 points (max_delta_abs)


    return 0; 
}


double LP(double *X, double *Y, double x, int n) {
    double mult, result = 0;
  
    for (int i = 0; i < n; i++) {
        mult = Y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                mult *= (x - X[j]) / (X[i] - X[j]);
        }
        result += mult;
    }
  
    return result; 
}


double f(double x) {
    return sin(x);
}