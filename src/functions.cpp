// functions.cpp
// (c) Tivole

#include "numerary.hpp"

namespace numerary
{
    
    short int Numerary::sgn (const double& x)
    {
       if (x > 0) return 1;
       if (x < 0) return -1;
       return 0;
    }



    double Numerary::max(double x, double y)
    {
        return x > y ? x : y;
    }



    double Numerary::min(double x, double y)
    {
        return x > y ? y : x;
    }

}
