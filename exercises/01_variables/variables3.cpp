#include <iostream>

// variables3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

int double_value_function(const int input) {
  // Solution fix the next line variable : note input cannot be modified
  return input;
}


#include <catch2/catch.hpp>

TEST_CASE("double_value_function") {
  assert (double_value_function(1) == 2);
  REQUIRE(double_value_function(0) == 0);
  REQUIRE(double_value_function(13) == 26);
}
