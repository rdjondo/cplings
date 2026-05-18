#include <concepts>
#include <iostream>
#include <string>
#include <vector>

// templates9.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts.

// A concept can express multiple requirements using a compound requires expression.
// Each requirement is a separate statement inside the requires { ... } body.
// All requirements must be satisfiable for the concept to evaluate to true.

// Step 1: Define a concept Summable requiring:
//   1. T is default-constructible: T{} is a valid expression
//   2. Two T values can be added: x + y is a valid expression returning T
// Hint: requires(const T x, const T y) { { T{} }; { x + y } -> std::same_as<T>; }

template <typename T>
concept Summable = ?;

// Step 2: Implement sum() constrained with Summable.
// Accumulate all values in the vector starting from T{} (zero/empty for the type).
template <Summable T>
T sum(const std::vector<T>& values) {
    T result{};
    // Fix: add each element of values to result
    ?
    return result;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_templates9_concept") {
    static_assert(Summable<int>);
    static_assert(Summable<double>);
    static_assert(Summable<std::string>);
}

TEST_CASE("test_templates9_sum") {
    REQUIRE(sum(std::vector<int>{1, 2, 3, 4, 5}) == 15);
    REQUIRE(sum(std::vector<double>{1.0, 2.5, 3.5}) == 7.0);
    REQUIRE(sum(std::vector<std::string>{"hello", " ", "world"}) == "hello world");
}
