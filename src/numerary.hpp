// numerary.hpp
// (c) Tivole

#pragma once
#ifndef NUMERARY_HPP
#define NUMERARY_HPP

// System includes
#include <iostream>
#include <cmath>
#include <cassert>

// Numerary includes

namespace numerary
{

    class Numerary
    {
    public:

        // Integration
        static double *integrate(double (*)(double), const double&, const double&, const std::string& = "simpson", const double& = 1.e-9);


        // Optimization
        static short int root(double (*)(double), double, double, double*, const std::string& = "bisection", const double& = 1.e-9);
        static short int minimum(double (*)(double), double, double, double*, const std::string& = "bisection", const double& = 1.e-9);
        static short int maximum(double (*)(double), double, double, double*, const std::string& = "bisection", const double& = 1.e-9);


        // Differentiation
        static double differentiate(double (*)(double), const short int&, const double&, const std::string& = "h", const double& = 0.00001);


        // Gamma functions
        static double incgamma(const double&, const double&, const double& = 1.e-12);


        // Regression
        static double* linear_regression(double*, double*, const int&);


        // Interpolation
        static double lagrange_polynomial(double*, double*, const double&, const int&);


        // Linear System of Equations
        static short int linear_systems_of_equations(double**, double*, double*, const int&, const std::string& = "gauss");


        // Nonlinear Systems of Equation
        static short int nonlinear_systems_of_equations(void (*)(double*, double*, int), double*, double*, int, const std::string& = "newton", double = 1.e-7, int = 100);


        // Ordinary differential equations
        static short int ordinary_differential_equations(double (*)(double, double), double*, double, double, double, const std::string& = "dorpi_4_5");

    private:

        Numerary();

        // Integration
        static double *integrate_simpson(double (*)(double), const double&, const double&, const double& = 1.e-9);


        // Functions
        static short int sgn (const double&);
        static double min(double, double);
        static double max(double, double);
        

        // Root finding functions
        static short int root_bisection(double (*)(double), double, double, double*, const double& = 1.e-9);
        static short int root_secant(double (*)(double), double, double, double*, const double& = 1.e-9);
        

        // Minimum finding functions
        static short int minimum_bisection(double (*)(double), double, double, double*, const double& = 1.e-9);
        static short int minimum_golden_ratio(double (*)(double), double, double, double*, const double& = 1.e-9);


        // Maximum finding functions
        static short int maximum_bisection(double (*)(double), double, double, double*, const double& = 1.e-9);
        static short int maximum_golden_ratio(double (*)(double), double, double, double*, const double& = 1.e-9);


        // Linear Systems of Equations
        static short int gauss_elimination(double**, double*, double*, const int&);


        // Nonlinear Systems of Equations
        static short int nonlinear_systems_of_equations_newton(void (*)(double*, double*, int), double*, double*, int, double = 1e-7, int = 100);


        // Ordinary Differential Equations
        static short int dorpi_4_5(double (*)(double, double), double*, double, double, double, double = 1.e-5, int = 12, double = 1.e-9, double = 0.125, double = 4.0);
    };

}


#endif
