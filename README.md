# Ti_Integral
Integral Approximation - Simpson's Rule

# Definition

Suppose ![f_x](img/f_x.gif) is defined on the interval ![from_a_to_b](img/a_b.gif). Then Simpson's rule on the entire interval approximates the definite integral of ![f_x](img/f_x.gif) on the interval by the formula

<p align="center">
  <img src="img/integral_s.gif">
</p>

The idea is that if ![f_x_eq_1](img/fx_eq_1.gif), ![x](img/x.gif), ![sqr_x](img/square_x.gif), this formula is an exact equality. So Simpson's rule gives the correct integral of any quadratic function. In general, Simpson's rule approximates ![f_x](img/f_x.gif) by a parabola through the points on the graph of ![f_x](img/f_x.gif) with ![x](img/x.gif)-coordinates ![a](img/a.gif), ![a_plus_b_div_2](img/a_plus_b_2.gif), ![b](img/b.gif).

Simpson's rule is usually applied by breaking the interval into ![N](img/N.gif) equal-sized subintervals, where ![N](img/N.gif) is an even number, and approximating the integral over each pair of adjacent subintervals using the above estimate.

That is, let ![f_x](img/equations.gif). Then

<p align="center">
  <img src="img/int_2.gif">
</p>

<p align="center">
  <img src="img/int_3.gif">
</p>

and so on. Adding these up gives

<p align="center">
  <img src="img/int_4.gif">
</p>