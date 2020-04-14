////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Description:                                                              //
//     This Runge-Kutta-Prince-Dormand method is an adaptive procedure for    //
//     approximating the solution of the differential equation y'(x) = f(x,y) //
//     with initial condition y(x0) = c.  This implementation evaluates       //
//     f(x,y) seven times per step using embedded fourth order and fifth order//
//     Runge-Kutta estimates to estimate the not only the solution but also   //
//     the error.                                                             //
//     The next step size is then calculated using the preassigned tolerance  //
//     and error estimate.                                                    //
//     For step i+1,                                                          //
//        y[i+1] = y[i] +  h/21369600* ( 1921409 * k1 + 9690880 * k3          //
//            + 13122270 * k4 - 5802111 * k5 + 1902912 * k6 + 534240 * k7)    //
//     where                                                                  //
//     k1 = f( x[i],y[i] ),                                                   //
//     k2 = f( x[i]+h/5, y[i] + h*k1/5 ),                                     //
//     k3 = f( x[i]+3h/10, y[i]+(h/40)*(3 k1 + 9 k2) ),                       //
//     k4 = f( x[i]+4h/5, y[i]+(h/45)*(44 k1 - 168 k2 + 160 k3) ),            //
//     k5 = f( x[i]+8h/9, y[i]+(h/6561)*(19372 k1 - 76080 k2 + 64448 k3       //
//                                                            - 1908 k4) ),   //
//     k6 = f( x[i]+h, y[i]+(h/167904)*(477901 k1 - 1806240 k2 + 1495424 k3   //
//                                                  + 46746 k4 - 45927 k5) )  //
//     k7 = f( x[i]+h, y[i]+(h/142464)*(12985 k1 + 64000 k3 + 92750 k4        //
//                                                  - 45927 k5 + 18656 k6) )  //
//     x[i+1] = x[i] + h.                                                     //
//                                                                            //
//     The error is estimated to be                                           //
//        err = h*( 26341 k1 - 90880 k3 + 790230 k4 - 1086939 k5              //
//                                     + 895488 k6 - 534240 k7 ) / 21369600   //
//     The step size h is then scaled by the scale factor                     //
//         scale = 0.8 * | epsilon * y[i] / [err * (xmax - x[0])] | ^ 1/4     //
//     The scale factor is further constrained 0.125 < scale < 4.0.           //
//     The new step size is h := scale * h.                                   //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

int dorpi_4_5(double (*f)(double, double), double y[], double x, double h, double xmax, double *h_next, double tolerance);