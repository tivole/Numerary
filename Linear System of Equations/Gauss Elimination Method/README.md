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

<p align="center">
    <img src="img/system_4.png">
</p>

Получают новую систему уравнений, в которой заменены соответствующие коэффициенты.

<p align="center">
    <img src="img/system_5.png">
</p>

After the indicated transformations have been completed, the first row and the first column are mentally deleted and continue the specified process for all subsequent equations until an equation with one unknown:

<p align="center">
    <img src="img/system_6.png">
</p>

## Reverse substitution

Reverse substitution involves the substitution of the value of ![x_n](img/x_n.gif) obtained in the previous step into the previous equations:

<p align="center">
    <img src="img/system_7.png">
</p>

This procedure is repeated for all remaining solutions:

<p align="center">
    <img src="img/system_8.png">
</p>