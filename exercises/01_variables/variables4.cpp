#include <iostream>

// variables4.cpp
// Make me pass the tests!
// Fix: double_var should return double the value of x.
// 'constexpr' means the compiler can evaluate this function at compile time.
// Note: x is const and cannot be modified: return a new computed value.

constexpr int double_var(const int x){
  return x;
}

int double_value_function(int x) {
  return double_var(x);
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("double_value_function and constexpr") {
  assert (double_value_function(1) == 2);
  REQUIRE(double_value_function(0) == 0);
  REQUIRE(double_value_function(13) == 26);
}
