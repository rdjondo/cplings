#include <string>
#include <type_traits>
#include <variant>

// variants4.cpp
// Make me compile and pass the tests!

// Step 1: Fill in the expression to obtain the plain type T from val.
// Step 2: Fill in the two type checks: one for int, one for std::string.

using Mixed = std::variant<int, std::string, double>;

std::string classify(const Mixed& v) {
    std::string result;

    std::visit([&result](const auto& val) {
        // Fix: add expression that gives the type of val

        if ? // Fix!
            result = "integer";
        else if ? // Fix!
            result = "text";
        else
            result = "other";
    }, v);

    return result;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_variants5_classify") {
    REQUIRE(classify(42)                 == "integer");
    REQUIRE(classify(std::string("hi"))  == "text");
    REQUIRE(classify(3.14)               == "other");
    REQUIRE(classify(-1)                 == "integer");
}
