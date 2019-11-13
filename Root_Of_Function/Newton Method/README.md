# Newton Method

## Method

In numerical analysis, Newton's method, also known as the Newton–Raphson method, named after Isaac Newton and Joseph Raphson, is a root-finding algorithm which produces successively better approximations to the roots (or zeroes) of a real-valued function. The most basic version starts with a single-variable function f defined for a real variable x, the function's derivative ![f'](img/derivative_f.gif), and an initial guess ![x_0](img/x_0.gif) for a root of ![f](img/f.gif). If the function satisfies sufficient assumptions and the initial guess is close, then ![step_1](img/step_1.gif) is a better approximation of the root than ![x_0](img/x_0.gif). Geometrically, (x1, 0) is the intersection of the x-axis and the tangent of the graph of ![f](img/f.gif) at (![x_0](img/x_0.gif), f(![x_0](img/x_0.gif))): that is, the improved guess is the unique root of the linear approximation at the initial point. The process is repeated as

<p align="center">
  <img src="img/Newton_Method.gif">
</p>
