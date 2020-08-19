Bisection Method
================

Usage
-----

Imagine that we want to minimize the following function:

.. math::
    :nowrap:

    \begin{equation}
        f(x) = 2x^2 - 5x +3, x \in [0, 2]
    \end{equation}

Then the code will look like this:

.. code-block:: cpp

    // example_minimum_bisection.cpp

    #include <iostream>
    #include "../src/numerary.hpp" // Numerary library

    using namespace std;
    using namespace numerary;

    /* Function to found local minimum */
    double f(double x) {
        return 2*x*x - 5*x + 3;
    }

    /* The main function */
    int main() {

        const double eps = 1.e-9; // eps value for method (1.e-9 by default)
        double a = 0; // "a" value of segment [a, b]
        double b = 2; // "b" value of segment [a, b]
        double minimum;
        short int is_found;

        is_found = Numerary::minimum(f, a, b, &minimum, "bisection", eps);

        if (is_found == 1) {
            cout << "Minimum is in x = " << minimum << endl;
        } else {
            cout << "Method not allowed!" << endl;
        }
        
        return 0;
    }
