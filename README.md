# Numerary

Numerary is open source Scientific Library that contains many numerical methods. Numerary have been written from scratch in C++.

# Features

The library covers a list of topics in numerical computing. Features are available for the following areas,

|                 |               |                                 |
| --------------- | ------------- | ------------------------------- |
| Root-Finding    | Minimizing    | Linear Systems Of Equations     |
| Integration     | Maximizing    | Nonlinear Systems Of Equations  |
| Differentiation | Regression    | Ordinary Differential Equations |
| Gamma Functions | Interpolation |                                 |

## Root-Finding

You can find the root of the function `f` at any segment `[a, b]`:

```cpp
#include <iostream>
#include "src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

double f(double x) {
    return sin(x); // Function to found the root
}

/* The main function */
int main() {
    double a = -1, b = 1; // "a" and "b" value of segment [a, b]
    double root; // Founded result of the root will be stored in this variable
    short int is_found;

    is_found = Numerary::root(f, a, b, &root);

    if (is_found == 1)
        cout << "Root is in x = " << root << endl;
    else
        cout << "Method not allowed!" << endl;

    return 0;
}
```

And you can do it with several numerical methods such as *Secant* and *Bisection* provided by the library. To do this, you simply need to specify the method that you want to apply as an additional parameter:

```cpp
Numerary::root(f, a, b, &root, "bisection"); // To use Bisection method
Numerary::root(f, a, b, &root, "secant"); // To use Secant method
```

In addition, you can adjust the results of the methods using additional parameters, such as `eps`:

```cpp
Numerary::root(f, a, b, &root, "secant", 1.e-9); // To set eps = 1.e-9
```

## Minimizing

You can minimize function `f` at any segment `[a, b]`:

```cpp
Numerary::minimum(f, a, b, &minimum);
```

For the `minimum` method, as with all other library methods, you can apply additional parameters:

```cpp
Numerary::minimum(f, a, b, &minimum, "golden_ratio", 1.e-7);
```

## Integration

You want to calculate the integrals, like this ![\int_{0}^{1} (5x^3 + 2\cos{x}) dx](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20%5Cint_%7B0%7D%5E%7B1%7D%20%285x%5E3%20+%202%5Ccos%7Bx%7D%29%20dx) ?

Numerary library can do it too. To do this, you just need to write:

```cpp
double *I = Numerary::integrate(f, from, to);

cout << "ans = " << I[0] << endl; // Value of calculated integral
cout << "err = " << I[1] << endl; // Error of calculated integral value
```

## Regression

With the helping of Numerary library you can also use regression models. Here is an example of linear regression:

```cpp
// Get predicted linear regression line
predicted_kc = Numerary::linear_regression(X, Y, N);

// Equation of regression line
cout << "y = " << predicted_kc[0] << "*x + " << predicted_kc[1] << endl; // y=k*x+c
```

<p align="center">
  <img width="45%" height="45%" src="./docs/img/linear-regression-1.png">
</p>

## Solving Nonlinear System Of Equations

Numerary library allows you to solve systems of nonlinear equations like:

<p align="center">
  <img src="https://latex.codecogs.com/gif.latex?%5Cleft%5C%7B%20%5Cbegin%7Barray%7D%7Bl%7D%20f%28x%2C%20y%29%3Dx%5E%7B2%7D&plus;y%5E%7B2%7D-5%20%5C%5C%20g%28x%2C%20y%29%3Dy-3%20x&plus;5%20%5Cend%7Barray%7D%20%5Cright.">
</p>

To do this, you just need to write:

```cpp
#include <iostream>
#include "../src/numerary.hpp" // Numerary library

using namespace std;
using namespace numerary;

/* System to solve */
void system(double *x, double *fv, int n) {
    fv[0] = x[0]*x[0] + x[1]*x[1] - 5;
    fv[1] = x[1] - 3*x[0] + 5;
}

int main() {
    double *x = new double[2], *fv = new double[2];
    short int is_solved;

    x[0] = 1; x[1] = 2; // Initial point

    is_solved = Numerary::nonlinear_systems_of_equations(system, x, fv, 2);

    if (is_solved == 1) {
        cout << "Solved!" << endl;
        cout << "x = " << x[0] << endl;
        cout << "y = " << x[1] << endl;
    } else {
        cout << "Method not allowed!";
    }

    delete[] x;
    delete[] fv;

    return 0;
}
```

## And Many Other Useful Features

In addition to the above, Numerary library has a lot more.

The detail use of these features is described in the [documentation](#documentation). The documentation for each method details the algorithm, definitions and examples of their use.

# Documentation

The Numerary documentation is hosted at [Read the docs](https://numerary.readthedocs.io/).

# License

Numerary is released under the MIT License. See the [LICENSE](./LICENSE) file for details.