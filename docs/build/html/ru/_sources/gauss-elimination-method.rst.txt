Gauss Elimination Method
========================

Algorithm
---------

The Gauss method is a classical method for solving a system of linear algebraic equations (SLAE). Consider a system of linear equations with real constant coefficients

.. math::
    :nowrap:

    \begin{align*}
        \left\{
            \begin{array}{ccc}
                a_{11}  \cdot x_{1}  + a_{12}  \cdot x_{2}  + & \cdots & +  a_{1 n} \cdot x_{n}=y_{1} \\
                a_{21}  \cdot x_{1}  + a_{22}  \cdot x_{2}  + & \cdots & +  a_{2 n} \cdot x_{n}=y_{2} \\
                                                              & \cdots & \\
                a_{n 1} \cdot x_{1}  + a_{n 2} \cdot x_{2}  + & \cdots & +  a_{n n} \cdot x_{n}=y_{n}
            \end{array}
        \right.
    \end{align*}

or in matrix form

.. math::
    :nowrap:

    \begin{align*}
        A x = y,
    \end{align*}

where

.. math::
    :nowrap:

    \begin{align*}
        A=\left(
            \begin{array}{ccc}
                a_{11}  & \dots & a_{1 n} \\
                        & \dots & \\
                a_{n 1} & \dots & a_{n n}
            \end{array}
        \right),
        \quad x=\left(
            \begin{array}{c}
                x_{1} \\
                \vdots \\
                x_{n}
            \end{array}
        \right),
        \quad y=\left(
            \begin{array}{c}
                y_{1} \\
                \vdots \\
                y_{m}
            \end{array}
        \right).
    \end{align*}

The Gauss method of solving a system of linear equations includes 2 stages:

- sequential (direct) exception;
- reverse substitution.


Sequential exception
^^^^^^^^^^^^^^^^^^^^

Gauss exceptions are based on the idea of ​​successive exceptions variables one at a time until only one equation remains with one variable on the left side. Then this equation is solved with respect to a single variable. Thus, the system of equations lead to a triangular (step) shape. For this, among the elements the first column of the matrix is ​​selected nonzero (and most often maximum) element and move it to its highest position by rearranging lines. Then all the equations are normalized, dividing it by the coefficient ai1, where i is the column number.

.. math::
    :nowrap:

     \begin{align*}
            \left\{
                \begin{array}{ccc}
                    x_{1}+\frac{a_{12}}{a_{11}}   \cdot x_{2} + & \cdots & + \frac{a_{1 n}}{a_{11}}  \cdot x_{n}=\frac{y_{1}}{a_{11}} \\
                    x_{1}+\frac{a_{22}}{a_{21}}   \cdot x_{2} + & \cdots & + \frac{a_{2 n}}{a_{21}}  \cdot x_{n}=\frac{y_{2}}{a_{21}} \\
                                                                & \cdots & \\
                    x_{1}+\frac{a_{n 2}}{a_{n 1}} \cdot x_{2} + & \cdots & + \frac{a_{n n}}{a_{n 1}} \cdot x_{n}=\frac{y_{n}}{a_{n 1}}
                \end{array}
            \right.
    \end{align*}


Then the first line obtained after the permutation is subtracted from the remaining lines:

.. math::
    :nowrap:

    \begin{align*}
            \left\{
                \begin{array}{r c r c r c l}
                    x_{1} & + & \frac{a_{12}}{a_{11}} \cdot x_{2}                                      & + \cdots + & \frac{a_{1 n}}{a_{11}} \cdot x_{n}                                       & = & \frac{y_{1}}{a_{11}} \\
                    0     & + & \left(\frac{a_{22}}{a_{21}}-\frac{a_{12}}{a_{11}}\right) \cdot x_{2}   & + \cdots + &  \left(\frac{a_{2 n}}{a_{21}}-\frac{a_{1 n}}{a_{11}}\right) \cdot x_{n}  & = & \left(\frac{y_{2}}{a_{21}}-\frac{y_{1}}{a_{11}}\right) \\
                          &&                                                                           &   \cdots   & \\
                    0     & + & \left(\frac{a_{n 2}}{a_{n 1}}-\frac{a_{12}}{a_{11}}\right) \cdot x_{2} & + \cdots + &  \left(\frac{a_{n n}}{a_{n 1}}-\frac{a_{1 n}}{a_{11}}\right) \cdot x_{n} & = & \left(\frac{y_{n}}{a_{n 1}}-\frac{y_{1}}{a_{11}}\right)
                \end{array}
            \right.
    \end{align*}

A new system of equations is obtained, in which the corresponding coefficients are replaced.

.. math::
    :nowrap:

    \begin{align*}
            \left\{
                \begin{array}{r c r c r c r}
                    x_{1} & + & a_{12}^{\prime} \cdot x_{2}  & + \cdots + & a_{1 n}^{\prime} \cdot x_{n} & = & y_{1}^{\prime} \\
                    0     & + & a_{22}^{\prime} \cdot x_{2}  & + \cdots + & a_{2 n}^{\prime} \cdot x_{n} & = & y_{2}^{\prime} \\
                          &&                                 &   \cdots   & \\
                    0     & + & a_{n 2}^{\prime} \cdot x_{2} & + \cdots + & a_{n n}^{\prime} \cdot x_{n} & = & y_{n}^{\prime}
                \end{array}
            \right.
    \end{align*}

After the indicated transformations have been completed, the first row and the first column are mentally deleted and continue the specified process for all subsequent equations until an equation with one unknown:

.. math::
    :nowrap:

    \begin{align*}
            \left\{
                \begin{array}{r c r c r c r c r}
                    x_{1} & + & a_{12}^{\prime} \cdot x_{2} & + & a_{13}^{\prime} \cdot x_{3}        & + \cdots + & a_{1 n}^{\prime} \cdot x_{n}               & = & y_{1}^{\prime} \\
                    0     & + & x_{2}                       & + & a_{23}^{\prime \prime} \cdot x_{3} & + \cdots + & a_{2 n}^{\prime \prime} \cdot x_{n}        & = & y_{2}^{\prime \prime} \\
                    0     & + & 0                           & + & x_{3}                              & + \cdots + & a_{3 n}^{\prime \prime \prime} \cdot x_{n} & = & y_{3}^{\prime \prime \prime} \\
                          &&                                &&                                       &   \cdots   & \\
                    0     & + & 0                           & + & 0                                  & + \cdots + & x_{n}                                      & = & y_{n}^{n \prime}
                \end{array}
            \right.
    \end{align*}


Reverse substitution
^^^^^^^^^^^^^^^^^^^^

Reverse substitution involves the substitution of the value of x_n obtained in the previous step into the previous equations:

.. math::
    :nowrap:

    \begin{align*}
            \begin{array}{rcl}
                x_{n-1}                                                                                                 & = & y_{n-1}^{(n-1)^{\prime}}-a_{(n-1) n}^{(n-1) \prime} \cdot x_{n} \\
                x_{n-2}+a_{(n-2)(n-1)}^{(n-2) \prime} \cdot x_{n-1}                                                     & = & y_{n-2}^{(n-2)^{\prime}}-a_{(n-2) n}^{(n-2) \prime} \cdot x_{n} \\
                \cdots \\
                x_{2}+a_{23}^{\prime \prime} \cdot x_{3}+\cdots+a_{2(n-1)}^{\prime \prime} \cdot x_{n-1}                & = & y_{2}^{\prime \prime}-a_{2 n}^{\prime \prime} \cdot x_{n} \\
                x_{1}+a_{12}^{\prime} \cdot x_{2}+a_{13}^{\prime} \cdot x_{3}+\cdots+a_{1(n-1)}^{\prime} \cdot x_{n-1}  & = & y_{1}^{\prime}-a_{1 n}^{\prime} \cdot x_{n}
            \end{array}
    \end{align*}

This procedure is repeated for all remaining solutions:

.. math::
    :nowrap:

    \begin{align*}
        \begin{array}{rcl}
            x_{n-2}                                                              & = & \left(y_{n-2}^{(n-2)^{\prime}}-a_{(n-2) n}^{(n-2)^{\prime}} \cdot x_{n}\right)-a_{(n-2)(n-1)}^{(n-2) \prime} \cdot x_{n-1} \\
            & \cdots & \\
            x_{2}+a_{23}^{\prime \prime} \cdot x_{3}+\cdots                      & = & \left(y_{2}^{\prime \prime}-a_{2 n}^{\prime \prime} \cdot x_{n}\right)-a_{2(n-1)}^{\prime \prime} \cdot x_{n-1} \\
            x_{1}+a_{12}^{\prime} \cdot x_{2}+a_{13}^{\prime} \cdot x_{3}+\cdots & = & \left(y_{1}^{\prime}-a_{1 n}^{\prime} \cdot x_{n}\right)-a_{1(n-1)}^{\prime} \cdot x_{n-1}
        \end{array}
    \end{align*}


Usage
-----

Imagine that we want to solve following linear system of equations:

.. math::
    :nowrap:

    \begin{align*}
        \left(
            \begin{array}{cc}
                2  & 1 \\
                -1 & 1
            \end{array}
        \right)
        \left(
            \begin{array}{c}
                x_{1} \\
                x_{2}
            \end{array}
        \right)
        =
        \left(
            \begin{array}{c}
                5 \\
                2
            \end{array}
        \right).
    \end{align*}

Then the code will look like this:

.. code-block:: cpp

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
