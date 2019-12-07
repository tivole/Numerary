// (c) Tivole

#include <stdio.h>
#include <math.h>


double differentiate(double (*)(double), double);
double f(double);
double df(double);


int main(void) {

    double x, dfx, real_dfx, error;

    x = 3.1415926535897932384626;
    dfx = differentiate(f, x);
    real_dfx = df(x);
    error = fabs(dfx - real_dfx);

    printf("My method = %lg\nReal value = %lg\nError = %lg\n", dfx, real_dfx, error);

    return 0;
}


double differentiate(double (*f)(double), double x) {
    double h = 0.00001;
    return (f(x + h) - f(x)) / h;
}


double f(double x) {
    return sin(x);
}


double df(double x) {
    return cos(x);
}