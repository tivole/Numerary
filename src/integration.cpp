// integral.cpp
// (c) Tivole

#include "numerary.hpp"

namespace numerary
{

    double* Numerary::integrate(double (*f)(double), const double& a, const double& b, const std::string& method, const double& eps)
    {
        if (method == "simpson") return integrate_simpson(f, a, b, eps);

        return NULL;
    }

    double* Numerary::integrate_simpson(double (*f)(double), const double& a, const double& b, const double& eps)
    {
        double *return_value = new double[2], x = a, I_1, I_2, dt, chi, h = b - a, h_new, error = 0, ans = 0, fx_1, fx_2, fx_3;
        
        while (x < b - eps) {
            // Simpson's rule formulas
            fx_1 = f(x), fx_2 = f(x + h/2), fx_3 = f(x + h);
            I_1 = (h/6) * (fx_1 + 4*fx_2 + fx_3);
            I_2 = (h/12) * (fx_1 + 4*f(x + h/4) + 2*fx_2 + 4*f(x + (3*h)/4) + fx_3);

            dt = (I_2 - I_1) / 15;
            chi = pow(fabs(dt)/eps, 0.2);

            if(chi > 1e4) chi = 1e4;
            if(chi < 1e-4) chi = 1e-4;

            h_new = 0.95 * h / chi;

            if(fabs(dt) < eps) {
                x += h;
                ans += I_2;
                error += fabs(dt);
            }

            h = h_new;
            if(x + h > b) h = b - x;
        }

        return_value[0] = ans;
        return_value[1] = error;

        return return_value;
    }

}
