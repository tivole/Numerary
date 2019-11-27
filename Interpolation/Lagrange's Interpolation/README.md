# Lagrange's Interpolation

## Lagrange polynomial

In numerical analysis, Lagrange polynomials are used for polynomial interpolation. For a given set of points ![(x_j, y_j)](img/x_j_y_j.gif) with no two ![x_j](img/x_j.gif) values equal, the Lagrange polynomial is the polynomial of lowest degree that assumes at each value ![x_j](img/x_j.gif) the corresponding value ![x_j](img/x_j.gif), so that the functions coincide at each point.

## Definition

Given a set of k + 1 data points

![(x_0, y_0)...(x_k, y_k)](img/formula_1.svg)

where no two ![x_j](img/x_j.gif) are the same, the <b>interpolation polynomial in the Lagrange form</b> is a linear combination

![(x_0, y_0)...(x_k, y_k)](img/formula_1.svg),

where ![0<=j<=k](img/0_is_greater_than_k.svg). Note how, given the initial assumption that no two ![x_j](img/x_j.gif) are the same, ![x_j - x_m not=0](img/x_j_x_m.svg), so this expression is always well-defined. The reason pairs ![x_i=x_j](img/x_i_eq_x_j.svg) with ![y_i not eq y_j](img/y_i_noteq_y_j.svg) are not allowed is that no interpolation function {\displaystyle L}L such that {\displaystyle y_{i}=L(x_{i})}y_{i}=L(x_{i}) would exist; a function can only get one value for each argument ![x_i](img/x_i.gif). On the other hand, if also {\displaystyle y_{i}=y_{j}}y_{i}=y_{j}, then those two points would actually be one single point.

