// (c) Tivole

/*
    Integral Approximation - Simpson's Rule
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1e-9 // The accuracy we want to get

double f(double x); // Function to integrate
double *Ti_Integrate(double (*f)(double), double a, double b); // Template of integrate function


int main(void) {

    double from = 0; // Lower bound of integral
    double to = 3.1415926535897932384626; // Higher bound of integral

    double *I = Ti_Integrate(f, from, to);

    printf("ans = %lg\nerr = %lg\n", I[0], I[1]);


    return 0;
}


double f(double x) {
    return sin(x); // You can write your own function to integrate here
}


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