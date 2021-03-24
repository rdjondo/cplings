#include <iostream>

// functions1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 



int function1() {
  callme();
  return 0;
}


#include <catch2/catch.hpp>

TEST_CASE("identity_function") {
  REQUIRE(function1() == 0);
}
