// example_first_order_derivative_h.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* Functiion to derive */
double f(double x) {
    return sin(x);
}

/* The main function */
int main() {

    const short int order = 1;
    double x, dy_dx;

    // Point where we want get value of derivative function
    x = M_PI;

    dy_dx = Numerary::differentiate(f, order, x);

    cout << "dy/dx (" << x << ") = " << dy_dx << endl;
    
    return 0;
}
