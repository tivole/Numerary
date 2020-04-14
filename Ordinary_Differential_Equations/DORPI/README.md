# Dormand-Prince Method

The one step calculation in the Dormand-Prince method is done as the following.

<p align="center">
    <img src="img/dorpi_coeffs.png">
</p>

Then the next step value ![yk+1](img/y_k_1.gif) is calculated as

<p align="center">
    <img src="img/yk1_formula.png">
</p>

This is a calculation by Runge-Kutta method of order 4. We have to be aware that we do not use ![k2](img/k_2.gif), though it is used to calculate ![k3](img/k_3.gif) and so on.

Next, we will calculate the next step value ![zk+1](img/z_k_1.gif) by Runge-Kutta method of order 5 as

<p align="center">
    <img src="img/zk1_formula.png">
</p>

We calculate the difference of the two next values ![|zk+1 − yk+1|](img/z-y.gif).

<p align="center">
    <img src="img/z-y_formula.png">
</p>

This is considered as the error in ![yk+1](img/y_k_1.gif). We calculate the optimal time interval ![hopt](img/h_opt.gif) as,

<p align="center">
    <img src="img/h_opt_formula.png">
</p>

where ![h](img/h.gif) in the right side is the old time interval. In practical programming, this new ![hopt](img/h_opt.gif) will be used in the next step of the calculation, though the author thinks it should be also used in the present calculation when it is very small, half or smaller for example.