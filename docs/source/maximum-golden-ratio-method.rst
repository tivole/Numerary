Golden Ratio Method
===================

Usage
-----

Imagine that we want to maximize the following function:

.. math::
    :nowrap:

    \begin{equation}
        f(x) = \frac{1}{1 + x^2}, x \in [-2, 2]
    \end{equation}

Then the code will look like this:

.. code-block:: cpp

    // example_maximum_golden_ratio.cpp

    #include <iostream>
    #include "../src/numerary.hpp" // Numerary library

    using namespace std;
    using namespace numerary;

    /* Function to found local maximum */
    double f(double x) {
        return 1.0 / (1.0 + x*x);
    }

    /* The main function */
    int main() {

        const double eps = 1.e-9; // eps value for method (1.e-9 by default)
        double a = -2; // "a" value of segment [a, b]
        double b = 2; // "b" value of segment [a, b]
        double maximum;
        short int is_found;

        is_found = Numerary::maximum(f, a, b, &maximum, "golden_ratio", eps);

        if (is_found == 1) {
            cout << "Maximum is in x = " << maximum << endl;
        } else {
            cout << "Method not allowed!" << endl;
        }
        
        return 0;
    }
