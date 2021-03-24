#include <iostream>

// functions3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 


void callme(int x) { 
	for (int i = 0; i < x; i++) {
		std::cout << "Ring! Call number " << i + 1 << "\n";
	}
}

int function_usage() {
  callme();
  return 0;
}



#include <catch2/catch.hpp>

TEST_CASE("function_usage") {
  REQUIRE(function_usage() == 0);
}
