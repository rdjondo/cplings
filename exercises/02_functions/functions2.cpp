#include <iostream>

// functions2.cpp
// Make me compile!
// Fix: the parameter 'x' is missing its type. Add the correct type declaration.

void callme(x) {
	for (int i = 0; i < x; i++) {
		std::cout << "Ring! Call number " << i + 1 << "\n";
	}
}

int function1() {
  callme(3);
  return 0;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("identity_function") {
  REQUIRE(function1() == 0);
}
