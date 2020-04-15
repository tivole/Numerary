// (c) Tivole

// main.c

#include <stdio.h>
#include <math.h>
#include "dorpi.c"

// Function (ordinary differential equation)
double fxy(double x, double y) {
    return (-1)*(2*y);
}

int main(void) {
    // Variable initialization
    double y[5], x0, x1, h, h_next;
    int a;

    // Initial point
    x0 = 1; y[0] = 3;
    
    // Point where we want calculate y(x1)
    x1 = 2.0;

    // Step size
    h = 0.01;

    // Dormand-Prince Method
    a = dorpi_4_5(fxy, y, x0, h, x1, &h_next, 1e-5);

    printf("a = %d\n\nResult = %lf\n", a, y[1]);

    return 0;
}