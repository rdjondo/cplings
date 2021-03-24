#include <iostream>
#include <vector>
#include <string>

// templates6.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the class Repeater a template class.
// function so that it could support generic inputs (vectors of both int and deque of double) 
// Use two generic types to accept both deque and vector.
// Use the keyword auto for the generic T returned by the function max


template<typename C, C v> // Value holder
struct constant_holder {
    static constexpr C value = v;
};

using true_type = constant_holder<bool, true>;
using false_type = constant_holder<bool, false>;

// //////////////////////////
// Checks if type is string
// //////////////////////////

template<typename T> // Value is false if is not specializing string
struct is_string : false_type {};

template<> // // Value is true if specializing string
struct is_string<std::string> : true_type {};

// Please follow the same pattern for checking if type is vector and pointers


bool test_templates6_0() {
    bool is_string_result = is_string<std::string>::value;
    return is_string_result;
}
bool test_templates6_1() {
    bool is_string_result = is_string<char>::value;
    return is_string_result;
}

bool test_templates6_2() {
    bool is_vector_result = is_vector<std::vector<int>>::value;
    return is_vector_result;
}
bool test_templates6_3() {
    bool is_vector_result = is_vector<char>::value;
    return is_vector_result;
}

bool test_templates6_4() {
    bool is_pointer_result = is_pointer<double*>::value;
    return is_pointer_result;
}
bool test_templates6_5() {
    bool is_pointer_result = is_pointer<double>::value;
    return is_pointer_result;
}



#include <catch2/catch.hpp>

TEST_CASE("test_template6") {
    REQUIRE(test_templates6_0() == true);
    REQUIRE(test_templates6_1() == false);
    REQUIRE(test_templates6_2() == true);
    REQUIRE(test_templates6_3() == false);
    REQUIRE(test_templates6_4() == true);
    REQUIRE(test_templates6_5() == false);
}
