#include <iostream>

// variables5.cpp
// Make me compile!
// Fix: initialize the const local variable y with the value 10.

int output_10_function() {
  const int y = ;
  return y;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("output_10_function") {
  assert (output_10_function() == 10);
}
