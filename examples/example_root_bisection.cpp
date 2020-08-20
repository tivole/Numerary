// example_root_bisection.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* Function to found the root */
double f(double x) {
    return sin(x);
}

/* The main function */
int main() {

    const double eps = 1.e-9; // eps value for method (1.e-9 by default)
    double a = -1; // "a" value of segment [a, b]
    double b = 1; // "b" value of segment [a, b]
    double root;
    short int is_found;

    is_found = Numerary::root(f, a, b, &root, "bisection", eps);

    if (is_found == 1) {
        cout << "Root is in x = " << root << endl;
    } else {
        cout << "Method not allowed!" << endl;
    }
    
    return 0;
}
