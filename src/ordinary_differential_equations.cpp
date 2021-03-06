// ordinary_differential_equations.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{

    short int Numerary::dorpi_4_5(double (*f)(double, double), double *y, double x, double h, double xmax, double tolerance, int attempts, double eps, double min_scale_factor, double max_scale_factor) {

        double h_next, scale, err, yy, temp_y[2], k1, k2, k3, k4, k5, k6, k7, h5;
        const double    r_45        = 1.0 / 45.0,
                        r_8_9       = 8.0 / 9.0,
                        r_6561      = 1.0 / 6561.0,
                        r_167904    = 1.0 / 167904.0,
                        r_142464    = 1.0 / 142464.0,
                        r_21369600  = 1.0 / 21369600.0;

        int i, last_interval = 0;

        if (xmax < x || h <= 0.0) return -2;

       
        h_next = h;
        y[1] = y[0];
        if (xmax == x) return 0; 
      
        h = min(h, xmax - x);

        tolerance /= (xmax - x);

        temp_y[0] = y[0];
        while ( x < xmax ) {
            scale = 1.0;
            for (i = 0; i < attempts; i++) {
                    //              Runge-Kutta Method               //
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

                if (err < eps) { scale = max_scale_factor; break; }
                yy = (fabs(temp_y[0]) < eps) ? tolerance : fabs(temp_y[0]);
                scale = 0.8 * sqrt( sqrt ( tolerance * yy /  err ) );
                scale = min( max(scale,min_scale_factor), max_scale_factor);
                if (err < (tolerance * yy)) break;
                h *= scale;
                if (x + h > xmax) h = xmax - x;
                else if (x + h + 0.5 * h > xmax) h = 0.5 * h;
            }
            if ( i >= attempts ) { h_next = h * scale; return -1; };
            temp_y[0] = temp_y[1];         
            x += h;
            h *= scale;
            h_next = h;
            if ( last_interval ) break;
            if (  x + h > xmax ) { last_interval = 1; h = xmax - x; }
            else if ( x + h + 0.5 * h > xmax ) h = 0.5 * h;
        }
        y[1] = temp_y[1];
        return 0;
    }



    short int Numerary::ordinary_differential_equations(double (*f)(double, double), double* y, double x, double h, double xmax, const std::string& method)
    {
        if (method == "dorpi_4_5") return dorpi_4_5(f, y, x, h, xmax);

        std::cerr << "Error - method \"" << method << "\" doesn't exist!";
        assert(false);

        return 3;
    }

}
