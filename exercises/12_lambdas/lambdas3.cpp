#include <algorithm>
#include <iostream>
#include <vector>

// lambdas3.cpp
// Make me compile and pass the tests!

// A lambda can capture local variables by reference using [&variable] or [&].
// Capturing by reference lets the lambda modify the captured variable.
// This is useful for accumulating state across multiple calls.

// Step 1: Use std::ranges::for_each with a lambda that captures count by reference ([&count]).
// The lambda should increment count once for every element it is called with.
std::size_t countElements(const std::vector<int>& numbers) {
    std::size_t count = 0;
    std::ranges::for_each(numbers, ?);
    return count;
}

// Step 2: Count how many comparisons std::ranges::sort makes.
// Write a lambda comparator that increments comparisons each time it's called,
// and also performs the actual comparison (returns x < y).
std::size_t countSortComparisons(std::vector<int> numbers) {
    std::size_t comparisons = 0;
    std::ranges::sort(numbers, ?);
    return comparisons;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_lambdas3_count_elements") {
    REQUIRE(countElements({1, 2, 3, 4, 5}) == 5);
    REQUIRE(countElements({}) == 0);
    REQUIRE(countElements({42}) == 1);
}

TEST_CASE("test_lambdas3_count_comparisons") {
    std::vector<int> v{5, 3, 1, 4, 2};
    std::size_t comps = countSortComparisons(v);
    REQUIRE(comps > 0);
    REQUIRE(comps < v.size() * v.size()); // a decent sort is better than O(n^2)
}
