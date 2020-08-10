Integral Approximation - Simpson's Rule
=======================================

Definition
----------

Suppose :math:`f(x)` is defined on the interval :math:`[a, b]`. Then Simpson's rule on the entire interval approximates the definite integral of :math:`f(x)` on the interval by the formula 

.. math::
    :nowrap:

    \begin{equation}
        \int_{a}^{b} f(x) d x \approx \frac{b-a}{6}\left(f(a)+4 f\left(\frac{a+b}{2}\right)+f(b)\right)
    \end{equation}

The idea is that if :math:`f(x) = 1, x, x^2`, this formula is an exact equality. So Simpson's rule gives the correct integral of any quadratic function. In general, Simpson's rule approximates :math:`f(x)` by a parabola through the points on the graph of :math:`f(x)` with :math:`x`-coordinates :math:`a, \frac{a+b}{2}, b`.

Simpson's rule is usually applied by breaking the interval into :math:`N` equal-sized subintervals, where :math:`N` is an even number, and approximating the integral over each pair of adjacent subintervals using the above estimate.

That is, let :math:`x_0=a, x_1=a+\frac{b-a}{N}, x_2=a+2\frac{b-x}{N}, \dots, x_{N-1}=a+(N-1)\frac{b-a}{N}, x_N=b`. Then

.. math::
    :nowrap:

    \begin{equation}
        \int_{a}^{x_{2}} f(x) d x \approx \frac{b-a}{3 N}\left(f(a)+4 f\left(x_{1}\right)+f\left(x_{2}\right)\right)
    \end{equation}

.. math::
    :nowrap:

    \begin{equation}
        \int_{x_2}^{x_{4}} f(x) d x \approx \frac{b-a}{3 N}\left(f(x_2)+4 f\left(x_{3}\right)+f\left(x_{4}\right)\right)
    \end{equation}

and so on. Adding these up gives

.. math::
    :nowrap:

    \begin{equation}
        \int_{a}^{b} f(x) d x \approx \frac{b-a}{3 N}\left(f(a)+4 f\left(x_{1}\right)+2 f\left(x_{2}\right)+4 f\left(x_{3}\right)+2 f\left(x_{4}\right)+\cdots+4 f\left(x_{N-1}\right)+f(b)\right).
    \end{equation}


Usage
-----

Imagine that we want to integrate the following expression:

.. math::
    :nowrap:

    \begin{equation}
        \int_{0}^{1} (5x^3 + 2\cos{x}) dx.
    \end{equation}

Then the code will look like this:

.. code:: cpp
    
    #include <iostream>
    #include "numerary.hpp"

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
