// (c) Tivole

#include <stdio.h>
#include <math.h>


double df_1(double (*)(double), double);
double df_2(double (*)(double), double);
double f(double);

double h = 1.0e-11;

int main(void) {

    double x, dfx_1, dfx_2;

    x = 5.0;
    dfx_1 = df_1(f, x);
    dfx_2 = df_2(f, x);
    
    printf("Method_1 = %.9lf\n", dfx_1);
    printf("Method_2 = %.9lf\n", dfx_2);

    return 0;
}


double df_1(double (*f)(double), double x) {
    return (f(x + h) - f(x)) / h;
}

double df_2(double (*f)(double), double x) {
    return (f(x + h) - f(x - h)) / (2*h);
}


double f(double x) {
    return sin(x);
}