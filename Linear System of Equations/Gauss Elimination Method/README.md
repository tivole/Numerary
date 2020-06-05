# Matrix Gauss Elimination Method

The Gauss method is a classical method for solving a system of linear algebraic equations (SLAE). Consider a system of linear equations with real constant coefficients

<p align="center">
    <img src="img/system_1.png">
</p>

or in matrix form

<p align="center">
    <img src="img/Ax_y.png">
</p>

where

<p align="center">
    <img src="img/system_2.png">
</p>

The Gauss method of solving a system of linear equations includes 2 stages:

* sequential (direct) exception;

* reverse substitution.

## Sequential exception

Gauss exceptions are based on the idea of ​​successive exceptions variables one at a time until only one equation remains with one variable on the left side. Then this equation is solved with respect to a single variable. Thus, the system of equations lead to a triangular (step) shape. For this, among the elements the first column of the matrix is ​​selected nonzero (and most often maximum) element and move it to its highest position by rearranging lines. Then all the equations are normalized, dividing it by the coefficient ![ai1](img/a_i1.gif), where ![i](img/i.gif) is the column number.

<p align="center">
    <img src="img/system_3.png">
</p>

Then the first line obtained after the permutation is subtracted from the remaining lines: