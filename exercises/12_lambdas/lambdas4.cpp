#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// lambdas4.cpp
// Make me compile and pass the tests!

// std::ranges algorithms take the container directly instead of begin()/end() pairs.
// std::erase_if(container, pred) is the C++20 replacement for the erase-remove idiom.

// Step 1: Use std::ranges::count_if with a lambda to count even numbers.
// A number n is even when n % 2 == 0.
std::ptrdiff_t countEvens(const std::vector<int>& numbers) {
    return std::ranges::count_if(numbers, ?);
}

// Step 2: Use std::ranges::find_if with a lambda to find the first word longer than 4 characters.
// Return the word, or an empty string if none is found.
std::string findFirstLongWord(const std::vector<std::string>& words) {
    auto it = std::ranges::find_if(words, ?);
    return it != words.end() ? *it : "";
}

// Step 3: Use std::erase_if to remove all negative numbers in a single call.
// std::erase_if(container, pred) removes every element for which pred returns true.
std::vector<int> removeNegatives(std::vector<int> numbers) {
    std::erase_if(numbers, ?);
    return numbers;
}


#include <catch2/catch.hpp>

TEST_CASE("test_lambdas4_count_evens") {
    REQUIRE(countEvens({1, 2, 3, 4, 5, 6}) == 3);
    REQUIRE(countEvens({1, 3, 5}) == 0);
    REQUIRE(countEvens({2, 4, 6, 8}) == 4);
}

TEST_CASE("test_lambdas4_find_long_word") {
    REQUIRE(findFirstLongWord({"hi", "hello", "world"}) == "hello");
    REQUIRE(findFirstLongWord({"a", "bb", "ccc"}) == "");
    REQUIRE(findFirstLongWord({"short", "tiny", "magnificent"}) == "short");
}

TEST_CASE("test_lambdas4_remove_negatives") {
    auto result = removeNegatives({-1, 2, -3, 4, 0, -5});
    REQUIRE(result == std::vector<int>{2, 4, 0});
}
