// example_minimum_golden_ratio.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* Function to found local minimum */
double f(double x) {
    return x*x + sin(3*x);
}

/* The main function */
int main() {

    const double eps = 1.e-9; // eps value for method (1.e-9 by default)
    double a = -1; // "a" value of segment [a, b]
    double b = 1; // "b" value of segment [a, b]
    double minimum;
    short int is_found;

    is_found = Numerary::minimum(f, a, b, &minimum, "golden_ratio", eps);

    if (is_found == 1) {
        cout << "Minimum is in x = " << minimum << endl;
    } else {
        cout << "Method not allowed!" << endl;
    }
    
    return 0;
}
