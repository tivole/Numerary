# Numerary

Numerary is open source Scientific Library that contains many numerical methods. Numerary have been written from scratch in C++.


# Features

The library covers a list of topics in numerical computing. Features are available for the following areas,

| | | |
|-|-|-|
| Root-Finding    | Minimizing    | Linear Systems Of Equations     |
| Integration     | Maximizing    | Nonlinear Systems Of Equations  |
| Differentiation | Regression    | Ordinary Differential Equations |
| Gamma Functions | Interpolation |                                 |


## Root-Finding
You can find the root of the function `f`:

```cpp
Numerary::root(f, a, b, &root);
```

And you can do it with several numerical methods such as Secant and Bisection provided by the library. To do this, you simply need to specify the method that you want to apply as an additional parameter:

```cpp
Numerary::root(f, a, b, &root, "bisection"); // To use Bisection method
Numerary::root(f, a, b, &root, "secant"); // To use Secant method
```

In addition, you can adjust the results of the methods using additional parameters, such as `eps`:


```cpp
Numerary::root(f, a, b, &root, "secant", 1.e-9); // To set eps = 1.e-9
```

## Minimizing
You can minimize function `f` at segment any `[a, b]`:

```cpp
Numerary::minimum(f, a, b, &minimum);
```



The use of these features is described in the [documentation](#documentation). The documentation for each method details the algorithm, definitions and examples of their use.


# Documenation

The Numerary documentation is hosted at [Read the docs](https://numerary.readthedocs.io/).