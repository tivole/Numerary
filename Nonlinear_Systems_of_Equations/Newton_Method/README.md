# Newton’s Method

<b>Newton’s method</b> is one of the most popular numerical methods, and is even referred by <i>Burden</i> and <i>Faires</i> as the most powerful method that is used to solve for the equation ![f(x) = 0](<img/f(x)=0.gif>). This method originates from the <i>Taylor’s series</i> expansion of the function ![f(x)](<img/f(x).gif>) about the point ![x1](img/x_1.gif):

<p align="center">
    <img src="img/formula_1.png">
</p>

where ![f](img/f.gif), and its first and second order derivatives, ![f'](img/f'.gif) and ![f''](img/f''.gif) are calculated at ![x1](img/x_1.gif). If we take the first two terms of the Taylor’s series expansion we have:

<p align="center">
    <img src="img/formula_2.png">
</p>

We then set <i>previous expression</i> to zero (i.e ![f(x) = 0](<img/f(x)=0.gif>) ) to find the root of the equation which gives us:

<p align="center">
    <img src="img/formula_3.png">
</p>

Rearranging the <i>previous expression</i> we obtain the next approximation to the root, giving us:

<p align="center">
    <img src="img/formula_4.png">
</p>

Thus generalizing <i>previous expression</i> we obtain Newton’s iterative method:

<p align="center">
    <img src="img/formula_5.png">
</p>

where ![xi→x](img/xi_to_bar_x.gif) (as ![i→∞](img/i_to_infty.gif)), and ![x](img/bar_x.gif) is the approximation to a root of the function ![f(x)](<img/f(x).gif>).

<br />

<b><i>Remark:</i></b> As the iterations begin to have the same repeated values i.e. as ![xi](img/x_i.gif) = ![x_i+1](img/x_ip1.gif) = ![x](img/bar_x.gif) this is an indication that ![f(x)](<img/f(x).gif>) converges to ![x](img/bar_x.gif). Thus ![xi](img/x_i.gif) is the root of the function ![f(x)](<img/f(x).gif>).

## Steps of Newton’s method

### Step 1:

Let ![x^(0)](img/initial_x0.gif) be a given initial vector.

### Step 2:

Calculate ![J(x^(0))](img/Jx0.gif) and ![F(x^(0))](img/Fx0.gif).

### Step 3:

We now have to calculate the vector ![y^(0)](img/y0.gif), where

<p align="center">
    <img src="img/vector_y.png">
</p>

In order to find ![y^(0)](img/y0.gif), we solve the linear system ![J(x(0))y(0)=−F(x(0))](img/expr_1.gif), using Gaussian Elimination.

<b><i>Remark:</i></b> Rearranging the system in Step 3, we get that ![y(0)=−J(x(0))−1F(x(0))](img/expr_2.gif). The significance of this is that, since ![y(0)=−J(x(0))−1F(x(0))](img/expr_2.gif), we can replace ![−J(x(0))−1F(x(0))](img/expr_3.gif) in our iterative formula with ![y^(0)](img/y0.gif). This result will yield that

<p align="center">
    <img src="img/formula_6.png">
</p>

### Step 4:

Once ![y^(0)](img/y0.gif) is found, we can now proceed to finish the first iteration by solving for ![x^(1)](img/x1.gif) . Thus using the result from Step 3, we have that

<p align="center">
    <img src="img/formula_7.png">
</p>

### Step 5:

Once we have calculated ![x^(1)](img/x1.gif), we repeat the process again, until ![x^(k)](img/xk.gif) converges to ![x](img/bar_x.gif). This indicates we have reached the solution to ![F(x)=0.gif](<img/F(x)=0.gif>), where ![x](img/bar_x.gif) is the solution to the system.

<br />

<b><i>Remark:</i></b> When a set of vectors converges, the norm ![||x^k - x^k-1||](img/expr_4.gif). This means that

<p align="center">
    <img src="img/formula_8.png">
</p>