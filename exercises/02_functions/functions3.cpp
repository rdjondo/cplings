#include <iostream>

// functions3.cpp
// Make me compile!
// Fix: callme() requires an argument: pass the correct value to it.

void callme(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << "Ring! Call number " << i + 1 << "\n";
	}
}

int function_usage() {
  callme();
  return 0;
}



#include <catch2/catch_test_macros.hpp>

TEST_CASE("function_usage") {
  REQUIRE(function_usage() == 0);
}
