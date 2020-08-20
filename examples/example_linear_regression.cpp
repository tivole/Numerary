// example_linear_regression.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* The main function */
int main() {

    const int N = 5; // Number of points
    double *X = new double[N], *Y = new double[N], *predicted_kc = new double[2];

    X[0] = 1.0; Y[0] = 1.0;
    X[1] = 2.0; Y[1] = 2.0;
    X[2] = 3.0; Y[2] = 1.3;
    X[3] = 4.0; Y[3] = 3.75;
    X[4] = 5.0; Y[4] = 2.25;

    
    // Get predicted linear regression line
    predicted_kc = Numerary::linear_regression(X, Y, N);

    // Equation of regression line
    cout << "y = " << predicted_kc[0] << "*x + " << predicted_kc[1] << endl;

    // Reallocate memory
    delete[] X;
    delete[] Y;
    delete[] predicted_kc;
    
    return 0;
}
