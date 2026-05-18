#include <iostream>
#include <string>

// pointers_references1.cpp
// Make me compile and pass the tests!
// Fix 1: new_data should be a pointer (int*), not a plain int.
// Fix 2: my_pointer_content must modify the VALUE pointed to, not the pointer address.
//        Use the dereference operator (*) to write through the pointer.

int* my_pointer_value_swap(int* old_data) {
    int new_data = old_data; // Fix: new_data should be a pointer (int*)
    return new_data;
}

void my_pointer_content(int * const value, int increment) { // the address of pointed value is const
    value += increment; // Fix: this modifies the local copy of the pointer: dereference it instead
}

// Test cases
#include <catch2/catch_test_macros.hpp>

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
