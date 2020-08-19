Bisection Method
================

Overview
--------

In mathematics, the **bisection method** is a root-finding method that applies to any continuous functions for which one knows two values with opposite signs. The method consists of repeatedly bisecting the interval defined by these values and then selecting the subinterval in which the function changes sign, and therefore must contain a root. It is a very simple and robust method, but it is also relatively slow. Because of this, it is often used to obtain a rough approximation to a solution which is then used as a starting point for more rapidly converging methods. The method is also called the **interval halving method**, the **binary search method**, or the **dichotomy method**.

.. image:: ../img/bisection-method.png
    :align: center


The Method
----------

The method is applicable for numerically solving the equation :math:`f(x) = 0` for the real variable :math:`x`, where :math:`f` is a continuous function defined on an interval :math:`[a, b]` and where :math:`f(a)` and :math:`f(b)` have opposite signs. In this case :math:`a` and :math:`b` are said to bracket a root since, by the intermediate value theorem, the continuous function :math:`f` must have at least one root in the interval :math:`(a, b)`.

At each step the method divides the interval in two by computing the midpoint :math:`c = \frac{a+b}{2}` of the interval and the value of the function :math:`f(c)` at that point. Unless :math:`c` is itself a root (which is very unlikely, but possible) there are now only two possibilities: either :math:`f(a)` and :math:`f(c)` have opposite signs and bracket a root, or :math:`f(c)` and :math:`f(b)` have opposite signs and bracket a root. The method selects the subinterval that is guaranteed to be a bracket as the new interval to be used in the next step. In this way an interval that contains a zero of :math:`f` is reduced in width by *50%* at each step. The process is continued until the interval is sufficiently small.

Explicitly, if :math:`f(a)` and :math:`f(c)` have opposite signs, then the method sets :math:`c` as the new value for :math:`b`, and if :math:`f(b)` and :math:`f(c)` have opposite signs then the method sets :math:`c` as the new :math:`a`. (If :math:`f(c)=0` then :math:`c` may be taken as the solution and the process stops.) In both cases, the new :math:`f(a)` and :math:`f(b)` have opposite signs, so the method is applicable to this smaller interval.


Iteration Tasks
^^^^^^^^^^^^^^^

1. Calculate :math:`c`, the midpoint of the interval, :math:`c=\frac{a+b}{2}`.
2. Calculate the function value at the midpoint, :math:`f(c)`.
3. If convergence is satisfactory (that is, :math:`c-a` is sufficiently small, or :math:`|f(c)|` is sufficiently small), return :math:`c` and stop iterating.
4. Examine the sign of :math:`f(c)` and replace either :math:`(a, f(a))` or :math:`(b, f(b))` with :math:`(c, f(c))` so that there is a zero crossing within the new interval.


Usage
-----

Imagine that we want to find the root of the following function:

.. math::
    :nowrap:

    \begin{equation}
        f(x) = \sin{(x)}, x \in [-1, 1]
    \end{equation}

Then the code will look like this:

.. code-block:: cpp

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
