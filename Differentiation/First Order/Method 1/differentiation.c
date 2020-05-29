// (c) Tivole

#include <stdio.h>
#include <math.h>


double differentiate(double (*)(double), double, double);
double f(double);
double df(double);
void test();


int main(void) {

    test();

    return 0;
}


double differentiate(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}


double f(double x) {
    return exp(x);
}


double df(double x) {
    return exp(x);
}

void test() {
    double dfx, real_dfx, error;

    double h[] = {1e-3, 1e-4, 1e-5, 1e-7, 1e-9, 1e-11};
    double x[] = {0.0, 1.0, 5.0};

    for (int i = 0; i < 3; i++) {
        printf("x = %lf\n", x[i]);
        printf("-----------------------------------------------------------\n");
        for (int j = 0; j < 6; j++) {
            dfx = differentiate(f, x[i], h[j]);
            real_dfx = df(x[i]);
            error = fabs(dfx - real_dfx);

            printf("h = %E\n", h[j]);
            printf("My method = %lg\nReal value = %lg\nError = %lg\n\n", dfx, real_dfx, error);
        }
        printf("\n-----------------------------------------------------------\n\n");
    }    
}