// (c) Tivole

#include <stdio.h>
#include <math.h>

#define max(x,y) ( (x) < (y) ? (y) : (x) )
#define min(x,y) ( (x) < (y) ? (x) : (y) )

#define ATTEMPTS 12
#define MIN_SCALE_FACTOR 0.125
#define MAX_SCALE_FACTOR 4.0

int Embedded_Prince_Dormand_v2_4_5(double (*f)(double, double), double y[], double x, double h, double xmax, double *h_next, double tolerance ) {

    double scale, err, yy, temp_y[2], k1, k2, k3, k4, k5, k6, k7, h5;
    const double    r_45        = 1.0 / 45.0,
                    r_8_9       = 8.0 / 9.0,
                    r_6561      = 1.0 / 6561.0,
                    r_167904    = 1.0 / 167904.0,
                    r_142464    = 1.0 / 142464.0,
                    r_21369600  = 1.0 / 21369600.0;

    int i, last_interval = 0;
   
   
    if (xmax < x || h <= 0.0) return -2;
   
    *h_next = h;
    y[1] = y[0];
    if (xmax == x) return 0; 
  
    h = min(h, xmax - x);

    tolerance /= (xmax - x);

    temp_y[0] = y[0];
    while ( x < xmax ) {
        scale = 1.0;
        for (i = 0; i < ATTEMPTS; i++) {
            h5 = 0.2 * h;
            k1 = (*f)(x, *temp_y);
            k2 = (*f)(x+h5, *temp_y + h5 * k1);
            k3 = (*f)(x+0.3*h, *temp_y + h * (0.075 * k1 + 0.225 * k2) );
            k4 = (*f)(x+0.8*h, *temp_y + r_45 * h * (44.0 * k1 - 168.0 * k2 + 160.0 * k3) );
            k5 = (*f)(x+r_8_9 * h,  *temp_y + r_6561 * h * (19372.0 * k1 - 76080.0 * k2 + 64448.0 * k3 - 1908.0 * k4) );
            k6 = (*f)(x+h, *temp_y + r_167904 * h * (477901.0 * k1 - 1806240.0 * k2 + 1495424.0 * k3 + 46746.0 * k4 - 45927.0 * k5) );
            k7 = (*f)(x+h, *temp_y + r_142464 * h * (12985.0 * k1 + 64000.0 * k3 + 92750.0 * k4 - 45927.0 * k5 + 18656.0 * k6) );
            *(temp_y+1) = *temp_y +  r_21369600 * h * (1921409.0 * k1 + 9690880.0 * k3 + 13122270.0 * k4 - 5802111.0 * k5 + 1902912.0 * k6 + 534240.0 * k7);
            err = fabs(r_21369600 * (26341.0 * k1 - 90880.0 * k3 + 790230.0 * k4 - 1086939.0 * k5 + 895488.0 * k6 - 534240.0 * k7) );

            if (err == 0.0) { scale = MAX_SCALE_FACTOR; break; }
            yy = (temp_y[0] == 0.0) ? tolerance : fabs(temp_y[0]);
            scale = 0.8 * sqrt( sqrt ( tolerance * yy /  err ) );
            scale = min( max(scale,MIN_SCALE_FACTOR), MAX_SCALE_FACTOR);
            if (err < (tolerance * yy)) break;
            h *= scale;
            if (x + h > xmax) h = xmax - x;
            else if (x + h + 0.5 * h > xmax) h = 0.5 * h;
        }
        if ( i >= ATTEMPTS ) { *h_next = h * scale; return -1; };
        temp_y[0] = temp_y[1];         
        x += h;
        h *= scale;
        *h_next = h;
        if ( last_interval ) break;
        if (  x + h > xmax ) { last_interval = 1; h = xmax - x; }
        else if ( x + h + 0.5 * h > xmax ) h = 0.5 * h;
    }
    y[1] = temp_y[1];
    return 0;
}
























double fxy(double x, double y) {
    return 3.0*y/x + x*x*x + x;
}


int main(void) {

    double y[5], x0, x1, tol, h, h_next, R;
    int a;

    x0 = 1;
    y[0] = 3;
    tol = 1.0e-5;
    x1 = -2.0;
    h = 0.01;


    a = Embedded_Prince_Dormand_v2_4_5(fxy, y, x0, h, x1, &h_next,tol);

    R = 2.0;

    printf("a = %d\n", a);
    printf("y[1] = %lf\n", y[1]);
    printf("Real ans = %lf\n", R*R*R*R - R*R + 3.0*fabs(R)*fabs(R)*fabs(R));


    return 0;
}