// incgamma.cpp
// (c) Tivole

#include "numerary.hpp"

namespace numerary
{
    
    double Numerary::incgamma(const double& a, const double& x, const double& eps)
    {
        double term=1.0/a, sum = 0;
        int n=1;
        while (term > eps) {
            sum = sum + term;
            term = term*(x/(a+n));
            n++;
        }

        return pow(x,a)*exp(-1*x)*sum;
    }

}
