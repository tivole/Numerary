add_library(
    numerary
    numerary.hpp
    integration.cpp
    root.cpp
    minimum.cpp
    maximum.cpp
    differentiation.cpp
    incgamma.cpp
    regression.cpp
    interpolation.cpp
    linear_systems_of_equations.cpp
    nonlinear_systems_of_equations.cpp
    ordinary_differential_equations.cpp
    functions.cpp
)

add_executable (demo ../main.cpp)
target_link_libraries (demo numerary)
