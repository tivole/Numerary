# Ti_Integral
Integral Approximation - Simpson's Rule


---
## Definition

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
  <img src="img/int_4.gif">.
</p>


---
## Numerical solution

```cpp
double *Ti_Integrate(double (*f)(double), double a, double b) {
    double *return_value = NULL, x = a, I_1, I_2, dt, chi, h = b - a, h_new, err = 0, ans = 0, fx_1, fx_2, fx_3;
    return_value = (double *) malloc(2 * sizeof (double));
    
    while (x < b - eps) {
        // Simpson's rule formulas
        fx_1 = f(x), fx_2 = f(x + h/2), fx_3 = f(x + h);
        I_1 = (h/6) * (fx_1 + 4*fx_2 + fx_3);
        I_2 = (h/12) * (fx_1 + 4*f(x + h/4) + 2*fx_2 + 4*f(x + (3*h)/4) + fx_3);

        dt = (I_2 - I_1) / 15;
        chi = pow(fabs(dt)/eps, 0.2);

        if(chi > 1e4) chi = 1e4;
        if(chi < 1e-4) chi = 1e-4;

        h_new = 0.95 * h / chi;

        if(fabs(dt) < eps) {
            x += h;
            ans += I_2;
            err += fabs(dt);
        }

        h = h_new;
        if(x + h > b) h = b - x;
    }

    return_value[0] = ans;
    return_value[1] = err;

    return return_value;
}
```


---
## Usage
```cpp
// Integrates function {f} from {lower_bound} to {higher_bound}
double *I = Ti_Integrate(f, lower_bound, higher_bound);
```

Function returns an array, where first number is value of integral, and the second is accuracy:
```cpp
printf("The integral is equal to %lg", I[0]); // ans
printf("Accuracy of calculation is %lg", I[1]); // error
```

You can write your own function to integrate from code
```cpp
double f(double x) {
    return sin(x); // You can write your own function to integrate here
}
```

You can also change lower or higher bound of integration
```cpp
double from = 0; // Lower bound of integral
double to = 3.1415926535897932384626; // Higher bound of integral
```

At the top of code you can edit an eps (accuracy of calculation)
```cpp
#define eps 1e-9 // The accuracy we want to get
```

---
## Example
Imagine that we want to integrate the following expression:

<p align="center">
  <img src="img/int_expr.gif">.
</p>

Then the code will look like this:
```cpp
// ...

/* The main function */
int main(void) {

    double *I = Ti_Integrate(f, 0, 1);

    printf("ans = %lg\nerr = %lg\n", I[0], I[1]);

    return 0;
}

/* Function to be integrated */
double f(double x) {
    return 5*pow(x, 3) + 2*cos(x);
}

// ...
```

Output will be:
```
ans = 2.93294
err = 6.07469e-09
```