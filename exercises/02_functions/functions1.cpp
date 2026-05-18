#include <iostream>

// functions1.cpp
// Make me compile!
// Fix: callme() is called but never defined. Add a definition for it above function1().

int function1() {
  callme();
  return 0;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("identity_function") {
  REQUIRE(function1() == 0);
}
