#include <iostream>
#include <string>

// pointers_references1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Fix the syntax mistakes to return the correct pointer values

int* my_pointer_value_swap(int* old_data) {
    int new_data = old_data; // Fix: new_data should be a pointer
    return new_data;
}

void my_pointer_content(int * const value, int increment) { // the address of pointed value is const 
    value += increment; 
}

// Test cases
#include <catch2/catch.hpp>

TEST_CASE("my_pointer_value_swap") {
    std::vector<int> test_values = {1, 5, 10, 15};
    for(int & val : test_values) {
        int* pointer = &val;
        int* new_data_ptr = my_pointer_value_swap(&val);
        REQUIRE(new_data_ptr  == &val); // new_data_ptr must point to val
    }
}

TEST_CASE("my_pointer_content") {
    std::vector<int> test_values = { 1, 5, 10, 15 };
    std::vector<int> test_increment = { -1, 1, -10, 3 };
    for (size_t i = 0; i < test_values.size(); i++)
    {
        int value = test_values[i];
        int* temp_ptr = &value;
        my_pointer_content(temp_ptr, test_increment[i]);
        REQUIRE(*temp_ptr == test_values[i] + test_increment[i]); // new_data_ptr must point to val
    }
}
