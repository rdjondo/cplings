#include <iostream>

// variables6.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

const int y = ; // y is a global variable. Fix it's definition.
int global_var_10_function() {
  return y; 
}


#include <catch2/catch.hpp>

TEST_CASE("output_10_function") {
  assert (global_var_10_function() == 10);
}
