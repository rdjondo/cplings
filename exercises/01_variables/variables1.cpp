#include <iostream>

// variables1.cpp
// Make me compile!
// Fix: assign the function parameter to the local variable x.

int identity_function(int input) {
  int x = ;
  return x;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("identity_function") {
  REQUIRE(identity_function(0) == 0);
  REQUIRE(identity_function(1) == 1);
  REQUIRE(identity_function(2) == 2);
  REQUIRE(identity_function(13) == 13);
}
