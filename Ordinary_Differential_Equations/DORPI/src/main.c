// (c) Tivole
#include <stdio.h>
#include <math.h>
#include "dorpi.c"

double fxy(double x, double y);

int main(void) {

    double y[5], x0, x1, tol, h, h_next, R;
    int a;

    x0 = 1;
    y[0] = 3;
    tol = 1.0e-5;
    x1 = 2.0;
    h = 0.01;


    a = dorpi_4_5(fxy, y, x0, h, x1, &h_next,tol);

    R = 2.0;

    printf("a = %d\n", a);
    printf("y[1] = %lf\n", y[1]);
    printf("Real ans = %lf\n", R*R*R*R - R*R + 3.0*fabs(R)*fabs(R)*fabs(R));

    return 0;
}

double fxy(double x, double y) {
    return 3.0*y/x + x*x*x + x;
}
