find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories (${TEST_SOURCE_DIR}/src
                     ${Boost_INCLUDE_DIRS}
                     )

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (test
    test_numerary.cpp
    test_root.cpp
    test_minimum.cpp
    test_maximum.cpp
    test_integrate.cpp
    test_differentiate.cpp
    test_gamma.cpp
    test_newton.cpp
    test_dorpi.cpp
    test_lagrange_polynomial.cpp
    test_regression.cpp
    test_linear_systems_of_equations.cpp
    )

target_link_libraries (test
                       numerary
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                       )
