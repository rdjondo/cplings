#include <iostream>

// variables1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

int identity_function(int input) {
  int x = ;
  return x;
}


#include <catch2/catch.hpp>

TEST_CASE("identity_function") {
  REQUIRE(identity_function(0) == 0);
  REQUIRE(identity_function(1) == 1);
  REQUIRE(identity_function(2) == 2);
  REQUIRE(identity_function(13) == 13);
}
