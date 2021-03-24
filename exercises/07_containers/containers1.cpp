#include <iostream>
#include <string>

// containers1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile. Replace the array with the appropriate container.


constexpr int num_elements = 4;
int my_sequence[num_elements]; // Fix change this type to the appropriate STL container

void test_containers1() {
	for (size_t i = 0; i < num_elements; i++)
	{
		my_sequence[i] = 42;
	}
}


#include <catch2/catch.hpp>

TEST_CASE("test_containers1") {
	test_containers1();
	std::cout << "Size of container : " << my_sequence.size() << "\n";
	REQUIRE(my_sequence.size() == num_elements); 

	for (const auto& e : my_sequence) {
		std::cout << "Value :" << e << "\n";
		REQUIRE(e == 42);
	}
}
