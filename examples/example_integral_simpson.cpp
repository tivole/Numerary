// example_integral_simpson.cpp

#include <iostream>
#include "../src/numerary.hpp"

using namespace std;
using namespace numerary;

/* Function to be integrated */
double f(double x) {
    return 5*pow(x, 3) + 2*cos(x);
}

/* The main function */
int main() {
    
    const double from = 0; // Lower bound of integral
    const double to = 1; // Upper bound of integral
    const string method = "simpson"; // Numerical method we will use for integration ("simpson" by default)
    const double eps = 1.e-9; // eps value for integration (1.e-9 by default)

    double *I = Numerary::integrate(f, from, to, method, eps);

    cout << "ans = " << I[0] << endl; // Value of calculated integral
    cout << "err = " << I[1] << endl; // Error of calculated integral value

    return 0;
}
