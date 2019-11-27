# Lagrange's Interpolation

## Lagrange polynomial

In numerical analysis, Lagrange polynomials are used for polynomial interpolation. For a given set of points ![(x_j, y_j)](img/x_j_y_j.gif) with no two ![x_j](img/x_j.gif) values equal, the Lagrange polynomial is the polynomial of lowest degree that assumes at each value ![x_j](img/x_j.gif) the corresponding value ![x_j](img/x_j.gif), so that the functions coincide at each point.

## Definition

Given a set of k + 1 data points

![(x_0, y_0)...(x_k, y_k)](img/formula_1.svg)

where no two ![x_j](img/x_j.gif) are the same, the <b>interpolation polynomial in the Lagrange form</b> is a linear combination

![L(x) = sum{y_j*l_j}](img/formula_2.svg),

of Lagrange basis polynomials

![l_j(x) = product](img/formula_3.svg)

where ![0<=j<=k](img/0_is_greater_than_k.svg). Note how, given the initial assumption that no two ![x_j](img/x_j.gif) are the same, ![x_j - x_m not=0](img/x_j_x_m.svg), so this expression is always well-defined. The reason pairs ![x_i=x_j](img/x_i_eq_x_j.svg) with ![y_i not eq y_j](img/y_i_noteq_y_j.svg) are not allowed is that no interpolation function ![L](img/L.gif) such that ![y_i_L_x](img/y_i_L_x.gif) would exist; a function can only get one value for each argument ![x_i](img/x_i.gif). On the other hand, if also ![y_i=y_j](img/y_i_eq_y_j.gif), then those two points would actually be one single point.

For all ![i neq j](img/i_neq_j.gif), ![ell_j_x](img/ell_j_x.gif) includes the term ![x - x_i](img/x_x_i.gif) in the numerator, so the whole product will be zero at ![x=x_i](img/x_eq_x_i.gif):

![l_j_neq_i(x) = product](img/formula_4.svg)

On the other hand,

![l_j(x_i) = 1](img/formula_5.svg)

In other words, all basis polynomials are zero at ![x=x_i](img/x_eq_x_i.gif), except ![ell_i_x](img/ell_i_x.gif), for which it holds that ![ell_i_x_eq1](img/ell_i_x_eq1.gif), because it lacks the ![x - x_i](img/x_x_i.gif) term.

It follows that ![ell_i_x_i_eq_y_i](img/ell_i_x_i_eq_y_i.gif), so at each point ![x_i](img/x_i.gif), ![L_x_i_eq_y_i](img/L_x_i_eq_y_i.gif), showing that ![L](img/L.gif) interpolates the function exactly.

## Algorithm

```cpp
double LP(double *X, double *Y, double x, int n) {
    double mult, result = 0;
  
    for (int i = 0; i < n; i++) {
        mult = Y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                mult *= (x - X[j]) / (X[i] - X[j]);
        }
        result += mult;
    }
  
    return result; 
}
```


## Runge's example

<p align="center">
  <img src="img/visualisation.png">
</p>

 The function ![f(x)](img/runge.gif) cannot be interpolated accurately on [−5, 5]
using a tenth-degree polynomial (dashed curve) with equally-spaced interpolation points. This
example that illustrates the difficulty that one can generally expect with high-degree polynomial
interpolation with equally-spaced points is known as <i>Runge’s example</i>.