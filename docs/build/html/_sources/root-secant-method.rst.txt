Secant Method
=============

Overview
--------

In numerical analysis, the **secant method** is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function :math:`f`. The secant method can be thought of as a finite-difference approximation of Newton's method. However, the method was developed independently of Newton's method and predates it by over 3000 years.

.. image:: ../img/secant-method.png
    :align: center
    :scale: 20%


The Method
----------

The secant method is defined by the recurrence relation

.. math::
    :nowrap:

    \begin{equation}
        x_{n}=x_{n-1}-f\left(x_{n-1}\right) \frac{x_{n-1}-x_{n-2}}{f\left(x_{n-1}\right)-f\left(x_{n-2}\right)}=\frac{x_{n-2} f\left(x_{n-1}\right)-x_{n-1} f\left(x_{n-2}\right)}{f\left(x_{n-1}\right)-f\left(x_{n-2}\right)}.
    \end{equation}

As can be seen from the recurrence relation, the secant method requires two initial values, :math:`x_0` and :math:`x_1`, which should ideally be chosen to lie close to the root.


Derivation Of The Method
------------------------

Starting with initial values :math:`x_0`` and :math:`x_1`, we construct a line through the points :math:`(x0, f(x0))` and :math:`(x1, f(x1))`, as shown in the picture above. In slope–intercept form, the equation of this line is

.. math::
    :nowrap:

    \begin{equation}
        y=\frac{f\left(x_{1}\right)-f\left(x_{0}\right)}{x_{1}-x_{0}}\left(x-x_{1}\right)+f\left(x_{1}\right).
    \end{equation}

The root of this linear function, that is the value of :math:`x` such that :math:`y=0` is

.. math::
    :nowrap:

    \begin{equation}
        x=x_{1}-f\left(x_{1}\right) \frac{x_{1}-x_{0}}{f\left(x_{1}\right)-f\left(x_{0}\right)}.
    \end{equation}

We then use this new value of :math:`x` as :math:`x_2` and repeat the process, using :math:`x_1` and :math:`x_2` instead of :math:`x_0` and :math:`x_1`. We continue this process, solving for :math:`x_3`, :math:`x_4`, etc., until we reach a sufficiently high level of precision (a sufficiently small difference between :math:`x_n` and :math:`x_n-1`):

.. math::
    :nowrap:

    \begin{equation}\begin{aligned}
        x_{2} &=x_{1}-f\left(x_{1}\right) \frac{x_{1}-x_{0}}{f\left(x_{1}\right)-f\left(x_{0}\right)} \\
        x_{3} &=x_{2}-f\left(x_{2}\right) \frac{x_{2}-x_{1}}{f\left(x_{2}\right)-f\left(x_{1}\right)} \\
        & \vdots \\
        x_{n} &=x_{n-1}-f\left(x_{n-1}\right) \frac{x_{n-1}-x_{n-2}}{f\left(x_{n-1}\right)-f\left(x_{n-2}\right)}.
    \end{aligned}\end{equation}


Usage
-----

Imagine that we want to minimize the following function:

.. math::
    :nowrap:

    \begin{equation}
        f(x) = \sin{x}, x \in [-1, 1]
    \end{equation}

Then the code will look like this:

.. code-block:: cpp

    // example_root_secant.cpp

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

        is_found = Numerary::root(f, a, b, &root, "secant", eps);

        if (is_found == 1) {
            cout << "Root is in x = " << root << endl;
        } else {
            cout << "Method not allowed!" << endl;
        }
        
        return 0;
    }
