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
        \quad b=\left(
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
