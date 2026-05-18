#include <iostream>
#include <vector>
#include <string>

// templates6.cpp
// Make me compile!
// Step 1: Add template specializations for is_vector and is_pointer.
// Follow the same pattern used for is_string above:
//   - a base template that inherits false_type (matches any type)
//   - a partial or full specialization that inherits true_type (matches the target)
// Hint for is_vector: specialize on std::vector<T> with a template parameter T.
// Hint for is_pointer: specialize on T* with a template parameter T.


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



#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_template6") {
    REQUIRE(test_templates6_0() == true);
    REQUIRE(test_templates6_1() == false);
    REQUIRE(test_templates6_2() == true);
    REQUIRE(test_templates6_3() == false);
    REQUIRE(test_templates6_4() == true);
    REQUIRE(test_templates6_5() == false);
}
