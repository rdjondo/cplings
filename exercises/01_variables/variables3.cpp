#include <iostream>

// variables3.cpp
// Make me pass the tests!
// Fix: the function should return double the input value.
// Note: 'const int input' means input cannot be modified: compute a new value instead.

int double_value_function(const int input) {
  return input;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("double_value_function") {
  assert (double_value_function(1) == 2);
  REQUIRE(double_value_function(0) == 0);
  REQUIRE(double_value_function(13) == 26);
}
