#include <string>
#include <variant>

// variants3.cpp
// Make me compile and pass the tests!

// std::visit(visitor, variant) calls visitor with the currently active alternative.
// A visitor is any callable with an operator() for every possible type in the variant.
// All operator() overloads must share the same return type.
//
// Step 1: Fill in the body of operator()(float) to format the result string.
// Step 2: In format(), pass the Formatter instance to std::visit.

using Number = std::variant<int, std::string, float>;

struct Formatter {
    std::string result;

    void operator()(int v)                { result = "int:" + std::to_string(v); }
    void operator()(const std::string& v) { result = "str:" + v; }
    void operator()(float v)              { result = ?; } // Fix!
};

std::string format(const Number& n) {
    Formatter f;
    std::visit(?, n); // Fix!
    return f.result;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_variants3_format") {
    REQUIRE(format(42)                == "int:42");
    REQUIRE(format(std::string("hi")) == "str:hi");
    REQUIRE(format(1.5f)              == "flt:1.500000");
}
