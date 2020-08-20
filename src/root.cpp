// root.cpp
// (c) Tivole

// Numerary includes
#include "numerary.hpp"

namespace numerary
{

    short int Numerary::root_bisection(double (*f)(double), double a, double b, double* root, const double& eps)
    {
        double fa, fb, sgn_fa, sgn_fb, x, fx, sgn_fx;

        fa = f(a);
        fb = f(b);

        sgn_fa = sgn(fa);
        sgn_fb = sgn(fb);
        
        if (sgn_fa == 0) { 
            *root = a;
            return 1;
        } else if (sgn_fb == 0) {
            *root = b;
            return 1;
        } else if (sgn_fa == sgn_fb) {
            return 0; // Method not allowed
        }

        while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
            x = (a + b)/2;
            fx = f(x);
            sgn_fx = sgn(fx);

            if (sgn_fa == sgn_fx) a = x;
            else if (sgn_fb == sgn_fx) b = x;
            else break;
        }
        
        *root = x;

        return 1;
    }



    short int Numerary::root_secant(double (*f)(double), double a, double b, double* root, const double& eps)
    {
        double fa, fb, sgn_fa, sgn_fb, c, fc, sgn_fc;
        
        fa = f(a);
        fb = f(b);
        
        sgn_fa = sgn(fa);
        sgn_fb = sgn(fb);

        if (sgn_fa == sgn_fb) return 0; // Method not allowed
        
        while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
            if (fabs(fa) < eps) {
                *root = a;
                return 1;
            } else if (fabs(fb) < eps) {
                *root = b;
                return 1;
            }
            
            c = b - (fb*(b - a)) / (fb - fa);
            fc = f(c);
            sgn_fc = sgn(fc);

            if (fa > fb) {
                if (sgn_fc > 0){
                    a = c;
                    fa = fc;
                } else if (sgn_fc < 0) {
                    b = c;
                    fb = fc;
                } else if (sgn_fc == 0) {
                    *root = c;
                    return 1;
                }
            } else if (fa < fb) {
                if (sgn_fc > 0) {
                    b = c;
                    fb = fc;
                } else if (sgn_fc < 0) {
                    a = c;
                    fa = fc;
                } else if (sgn_fc == 0) {
                    *root = c;
                    return 1;
                }
            }
        }

        return 0;
    }



    short int Numerary::root(double (*f)(double), double a, double b, double* root, const std::string& method, const double& eps)
    {
        if (method == "bisection") return root_bisection(f, a, b, root, eps);
        if (method == "secant") return root_secant(f, a, b, root, eps);

        std::cerr << "Error - method \"" << method << "\" doesn't exist!";
        assert(false);

        return 2;
    }

}
