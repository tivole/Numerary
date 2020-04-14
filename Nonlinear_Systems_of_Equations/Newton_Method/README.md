# Newton’s Method

Newton’s method is one of the most popular numerical methods, and is even referred by Burden and Faires as the most powerful method that is used to solve for the equation ![f(x) = 0](img/f(x)=0.gif). This method originates from the Taylor’s series expansion of the function ![f(x)](img/f(x).gif) about the point ![x1](img/x_1.gif):

<p align="center">
    <img src="img/formula_1.png">
</p>

where ![f](img/f.gif), and its first and second order derivatives, ![f'](img/f'.gif) and ![f''](img/f''.gif) are calculated at x1. If we take the first two terms of the Taylor’s series expansion we have:

<p align="center">
    <img src="img/formula_2.png">
</p>

We then set previous expression to zero (i.e ![f(x) = 0](img/f(x)=0.gif)) to find the root of the equation which gives us:

<p align="center">
    <img src="img/formula_3.png">
</p>

Rearranging the previous expression we obtain the next approximation to the root, giving us:

<p align="center">
    <img src="img/formula_4.png">
</p>

Thus generalizing previous expression we obtain Newton’s iterative method:

<p align="center">
    <img src="img/formula_5.png">
</p>

where ![xi→x](img/xi_to_bar_x.gif) (as ![i→∞](img/i_to_infty.gif)), and ![x](img/bar_x.gif) is the approximation to a root of the function ![f(x)](img/f(x).gif).

<br />

<b><i>Remark:</i></b> As the iterations begin to have the same repeated values i.e. as ![xi](img/x_i.gif) = ![x_i+1](img/x_ip1.gif) = ![x](img/bar_x.gif) this is an indication that ![f(x)](img/f(x).gif) converges to ![x](img/bar_x.gif). Thus ![xi](img/x_i.gif) is the root of the function ![f(x)](img/f(x).gif).