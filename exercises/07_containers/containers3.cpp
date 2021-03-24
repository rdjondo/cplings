#include <iostream>
#include <string>
#include <?>

// containers3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile. Replace the array with the appropriate container.


? my_sequence; // Change this type to the appropriate STL

void test_containers3() {
	std::cout << "There should be only one element of only 5 elements  value (no duplicates) : \n";
	my_sequence[0] = 100;
	my_sequence[50] = 200;
	my_sequence[100] = 300;
	my_sequence[150] = 400;
	my_sequence[200] = 500;
}


#include <catch2/catch.hpp>

TEST_CASE("test_containers3") {
	test_containers3();
	std::cout << "Size of container : " << my_sequence.size() << "\n";
	REQUIRE(my_sequence.size() == 5);
	int test_value = 100;
	for (const auto& e : my_sequence) {
		std::cout << "Value :" << e.first << " -> " << e.second << "\n";
		REQUIRE(e.second == test_value);
		test_value += 100;
	}
}
