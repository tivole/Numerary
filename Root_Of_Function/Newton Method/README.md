# Newton Method

## Method

In numerical analysis, <b>Newton's method</b>, also known as the <b>Newton–Raphson method</b>, named after <i>Isaac Newton</i> and <i>Joseph Raphson</i>, is a root-finding algorithm which produces successively better approximations to the roots (or zeroes) of a real-valued function. The most basic version starts with a single-variable function ![f](img/f.gif) defined for a real variable x, the function's derivative ![f'](img/derivative_f.gif), and an initial guess ![x_0](img/x_0.gif) for a root of ![f](img/f.gif). If the function satisfies sufficient assumptions and the initial guess is close, then ![step_1](img/step_1.gif) is a better approximation of the root than ![x_0](img/x_0.gif). Geometrically, ![(x1, 0)](img/x_1_0.gif) is the intersection of the x-axis and the tangent of the graph of ![f](img/f.gif) at ![x_0_f_x_0](img/x_0_f_x_0.gif): that is, the improved guess is the unique root of the linear approximation at the initial point. The process is repeated as ![step_n_plus_1](img/step_n_plus_1.gif) until a sufficiently precise value is reached. This algorithm is first in the class of <i>Householder's methods</i>, succeeded by <i>Halley's method</i>. The method can also be extended to complex functions and to systems of equations.

<p align="center">
  <img src="img/Newton_Method.gif">
</p>
