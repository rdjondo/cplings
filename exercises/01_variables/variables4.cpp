#include <iostream>

// variables4.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// This example showcases the use of a constexpr (computable at compile time)
constexpr int double_var(const int x){
  // Solution fix the next line variable : note input cannot be modified
  return x;
}

int double_value_function(int x) {
  return double_var(x); 
}


#include <catch2/catch.hpp>

TEST_CASE("double_value_function and constexpr") {
  assert (double_value_function(1) == 2);
  REQUIRE(double_value_function(0) == 0);
  REQUIRE(double_value_function(13) == 26);
}
