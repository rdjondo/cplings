#include <iostream>

// functions2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 


void callme(x) {
	for (int i = 0; i < x; i++) {
		std::cout << "Ring! Call number " << i + 1 << "\n";
	}
}

int function1() {
  callme(3);
  return 0;
}


#include <catch2/catch.hpp>

TEST_CASE("identity_function") {
  REQUIRE(function1() == 0);
}
