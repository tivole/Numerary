// example_incomplete_gamma_function.cpp

#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* The main function */
int main() {

    double value;

    value = Numerary::incgamma(2, 1);

    cout << "IncGamma(2, 1) = " << value << endl;
    
    return 0;
}
