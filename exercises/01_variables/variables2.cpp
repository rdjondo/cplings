#include <iostream>

// variables2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

int type_function(int input) {
  x = input; 
  return x;
}


#include <catch2/catch.hpp>

TEST_CASE("type_function") {
  REQUIRE(type_function(0) == 0);
  REQUIRE(type_function(1) == 1);
  REQUIRE(type_function(13) == 13);
}
