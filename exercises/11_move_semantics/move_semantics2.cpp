#include <iostream>
#include <memory>
#include <vector>

// move_semantics2.cpp
// Make me compile and pass the tests!

// Step 1: std::unique_ptr cannot be copied — ownership is exclusive.
// To transfer a unique_ptr into a container (or another variable),
// you must explicitly use std::move() to cast it to an rvalue reference.
//
// Fix every line marked with "// Fix" by wrapping the variable in std::move().

std::vector<std::unique_ptr<int>> buildNumbers() {
    std::vector<std::unique_ptr<int>> numbers;

    auto a = std::make_unique<int>(10);
    auto b = std::make_unique<int>(20);
    auto c = std::make_unique<int>(30);

    numbers.push_back(a);  // Fix: cannot copy unique_ptr, use std::move(a)
    numbers.push_back(b);  // Fix: use std::move(b)
    numbers.push_back(c);  // Fix: use std::move(c)

    return numbers;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_move_semantics2") {
    auto numbers = buildNumbers();

    REQUIRE(numbers.size() == 3);
    REQUIRE(*numbers[0] == 10);
    REQUIRE(*numbers[1] == 20);
    REQUIRE(*numbers[2] == 30);
}
