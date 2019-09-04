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


    double *x = Ti_Integrate(f, 0, 3.141592653589793);

    printf("%lg\t%lg\n", x[0], x[1]);


    return 0;
}


double f(double x) {
    return sin(x);
}


double *Ti_Integrate(double (*f)(double), double a, double b) {
    double *return_value = NULL, x = a, I_1, I_2, dt, H, h = b - a, h_new, err = 0, ans = 0;
    return_value = (double *) malloc(2 * sizeof (double));
    
    while (x < b - eps) {
        I_1 = (h/6) * (f(x) + 4*f(x + h/2) + f(x+h));
        I_2 = (h/12) * (f(x) + 4*f(x + h/4) + 2*f(x + h/2) + 4*f(x + (3*h)/4) + f(x + h));

        dt = (I_2 - I_1) / 15;
        H = pow(fabs(dt)/eps, 0.2);

        if(H > 10) H = 10;
        if(H < 0.1) H = 0.1;

        h_new = 0.95 * h / H;

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