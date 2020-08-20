// example_dorpi.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* Equation to solve */
double equation(double x, double y) {
    return 3.0*y/x + x*x*x + x;
}

/* The main function */
int main() {

    double *y = new double[2];
    double x0, x, h;
    short int is_solved;

    // Initial point
    x0 = 1; y[0] = 3;
    
    // Point where we want calculate y(x)
    x = 2.0;

    // Step size
    h = 0.01;

    is_solved = Numerary::ordinary_differential_equations(equation, y, x0, h, x, "dorpi_4_5");

    if (is_solved == 0) {
        cout << "Solved!" << endl;
        cout << "y(" << x << ") = " << y[1] << endl;
    } else {
        cout << "Method not allowed!" << endl;
    }

    delete[] y;
    
    return 0;
}
