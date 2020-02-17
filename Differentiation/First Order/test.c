// (c) Tivole

#include <stdio.h>
#include <math.h>


double differentiate(double (*)(double), double);
double f(double);

int main(void) {

    double dfx, x;

    x = 5.0;
    dfx = differentiate(f, x);

    printf("My method = %.10lg\n", dfx);

    return 0;
}


double differentiate(double (*f)(double), double x) {
    double h = 1e-11; // 0.000001;
    return (f(x + h) - f(x)) / h;
}


double f(double x) {
    return exp(x);
}