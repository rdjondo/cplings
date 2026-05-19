#include <iostream>
#include <string>
#include <variant>

// variants1.cpp
// Make me compile and pass the tests!

// std::variant<A, B, C> holds exactly one of A, B, or C at a time.
// Assigning a new value changes the active alternative.
//
// std::get<T>(v)               — extracts the stored T; throws std::bad_variant_access if wrong type.
// std::holds_alternative<T>(v) — returns true if v currently holds a T.
//
// Step 1: Fill in the three std::get calls with the correct type.
// Step 2: Fill in std::holds_alternative with the correct type.

using Token = std::variant<int, std::string, double>;

int asInt(const Token& v) {
    return std::get<?>(v);              // Fix: which type holds an int?
}

std::string asString(const Token& v) {
    return std::get<?>(v);              // Fix: which type holds the string?
}

bool holdsDouble(const Token& v) {
    return std::holds_alternative<?>(v); // Fix: check for double
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_variants1_get") {
    Token v = 42;
    REQUIRE(asInt(v) == 42);

    v = std::string("hello");
    REQUIRE(asString(v) == "hello");

    v = 3.14;
    REQUIRE(holdsDouble(v));
}

TEST_CASE("test_variants1_throws") {
    Token v = 99;
    REQUIRE_THROWS_AS(asString(v), std::bad_variant_access);
}
