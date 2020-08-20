// example_newton.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* System to solve */
void system(double *x, double *fv, int n) {
    fv[0] = x[0]*x[0] + x[1]*x[1] - 5;
    fv[1] = x[1] - 3*x[0] + 5;
}

/* The main function */
int main() {

    const int maxiter = 100; // Maximum interations for set method (100 by default)
    const double eps = 1.e-7; // eps value for method (1.e-7 by default)
    double *x = new double[2], *fv = new double[2];
    short int is_solved;
        
    // Initial point
    x[0] = 1; x[1] = 2;

    is_solved = Numerary::nonlinear_systems_of_equations(system, x, fv, 2, "newton", eps, maxiter);

    if (is_solved == 1) {
        cout << "Solved!" << endl;
        cout << "x = " << x[0] << endl;
        cout << "y = " << x[1] << endl;
    } else {
        cout << "Method not allowed!";
    }

    delete[] x;
    delete[] fv;
    
    return 0;
}
