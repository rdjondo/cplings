#include <iostream>
#include <string>

// pointers_references2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Fix the syntax mistakes to return the correct reference values

void my_reference_content(int value, int increment) {
    value += increment; // Don't change this line
}

#include <catch2/catch.hpp>

TEST_CASE("my_reference_content") {
    std::vector<int> values = { 1, 5, 10, 15 };
    std::vector<int> increments = { -1, 1, -10, 3 };

    for (size_t i = 0; i < values.size(); i++)
    {
        const int old_copy = values[i];
        my_reference_content(values[i], increments[i]);
        REQUIRE(values[i] == old_copy + increments[i]); // new_data_ptr must point to val
    }
}
