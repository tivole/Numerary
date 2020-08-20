// differentiate.cpp
// (c) Tivole

#include "numerary.hpp"

namespace numerary
{
    
    double Numerary::differentiate(double (*f)(double), const short int& order, const double& x, const std::string& method, const double& h)
    {
        if (order == 1) {
            if (method == "h") return (f(x + h) - f(x)) / h;
            if (method == "2h") return (f(x + h) - f(x - h)) / (2*h);
        } else if (order == 2) {
            // h2 (h^2)
            return (f(x + h) - 2*f(x) + f(x - h)) / (h*h);
        }

        std::cerr << "Error - method \"" << method << "\" or order \"" << order << "\" doesn't exist!";
        assert(false);

        return 0;
    }

}
