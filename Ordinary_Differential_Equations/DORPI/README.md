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
