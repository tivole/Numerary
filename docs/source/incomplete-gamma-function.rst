Incomplete Gamma Function
=========================

Definition
----------

.. math::
    :nowrap:

    \begin{equation}
        \gamma(s, x)=\int_{0}^{x} t^{s-1} \mathrm{e}^{-t} \mathrm{d} t
    \end{equation}


Usage
-----

Imagine that we want to calculate the value of:

.. math::
    :nowrap:

    \begin{equation}
       \gamma(2, 1) 
    \end{equation}

Then the code will look like this:

.. code-block:: cpp

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

