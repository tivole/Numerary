# Secant Method

## Secant Method

In numerical analysis, the <b>secant method</b> is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function ![f](img/f.gif). The secant method can be thought of as a finite-difference approximation of Newton's method. However, the method was developed independently of Newton's method and predates it by over 3000 years.

<p align="center">
  <img src="img/Secant_Method.png">
</p>


## The method

The secant method is defined by the recurrence relation
![formula](img/formula.svg)
As can be seen from the recurrence relation, the secant method requires two initial values, x0 and x1, which should ideally be chosen to lie close to the root.