#include <iostream>

// variables6.cpp
// Make me compile!
// Fix: initialize the global const variable y with the value 10.

const int y = ; // y is a const global variable: accessible throughout this file.
int global_var_10_function() {
  return y;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("output_10_function") {
  assert (global_var_10_function() == 10);
}
