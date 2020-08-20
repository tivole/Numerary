// example_gauss_elimination.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* The main function */
int main() {

    double **a = new double*[2];
    double *y = new double[2];
    double *x = new double[2];
    short int is_solved;

    for (int i = 0; i < 2; i ++)
        a[i] = new double[2];


    // Initialize matrix A
    a[0][0] = 2;
    a[0][1] = 1;

    a[1][0] = -1;
    a[1][1] = 1;

    // Initialize vector y
    y[0] = 5;
    y[1] = 2;

    is_solved = Numerary::linear_systems_of_equations(a, y, x, 2, "gauss");

    if (is_solved == 1) {
        cout << "System solved!" << endl;
        cout << "x = (" << x[0] << ", " << x[1] << ")" << endl;
    } else {
        cout << "Method is not allowed!";
    }

    for (int i = 0; i < 2; i++) delete[] a[i];

    delete[] a;
    delete[] x;
    delete[] y;
    
    return 0;
}
