// example_lagrange_polynomial.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* The main function */
int main() {

    const int N = 5;
    double *X = new double[N], *Y = new double[N];
    double y, x;

    // Points to interpolate
    X[0] = 2.0; Y[0] = 10.0;
    X[1] = 3.0; Y[1] = 15.0;
    X[2] = 5.0; Y[2] = 25.0;
    X[3] = 8.0; Y[3] = 40.0;
    X[4] = 12.0; Y[4] = 60.0;
    
    // Point where we want to get value of Lagrange Polynomial
    x = 7.0;

    y = Numerary::lagrange_polynomial(X, Y, x, N);

    cout << "y(" << x << ") = " << y << endl;

    delete[] X;
    delete[] Y;
    
    return 0;
}
