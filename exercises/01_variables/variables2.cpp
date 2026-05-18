#include <iostream>

// variables2.cpp
// Make me compile!
// Fix: x is used but never declared. Declare it using the 'auto' keyword.

int type_function(int input) {
  x = input;
  return x;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("type_function") {
  REQUIRE(type_function(0) == 0);
  REQUIRE(type_function(1) == 1);
  REQUIRE(type_function(13) == 13);
}
