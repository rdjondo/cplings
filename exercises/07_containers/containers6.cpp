#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// containers6.cpp
// Make me compile and pass the tests!

// Both algorithms below follow the same pattern:
//   1. Call a std::ranges algorithm that returns a subrange of "unwanted" elements.
//   2. Erase that subrange with vector::erase(subrange.begin(), subrange.end()).
//
// std::ranges::stable_partition(range, predicate)
//   Keeps elements satisfying the predicate at the front (preserving order).
//   Returns a subrange pointing at the elements that did NOT satisfy the predicate.
//
// std::ranges::remove_if(range, predicate)
//   Moves matching elements to the end and returns a subrange of those elements.
//   Erase it to physically remove them.

// Step 1: Remove even numbers — keep where n % 2 != 0 (odd).
void removeEvens(std::vector<int>& numbers) {
    auto tail = std::ranges::stable_partition(numbers, ?); // Fix: predicate keeping odd numbers
    numbers.erase(tail.begin(), tail.end());
}

// Step 2: Remove negative numbers — match where n < 0.
void removeNegatives(std::vector<int>& numbers) {
    auto tail = std::ranges::remove_if(numbers, ?); // Fix: predicate matching negative numbers
    numbers.erase(tail.begin(), tail.end());
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_containers6_remove_evens") {
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    removeEvens(numbers);
    REQUIRE(numbers == std::vector<int>{1, 3, 5, 7, 9});
}

TEST_CASE("test_containers6_remove_negatives") {
    std::vector<int> numbers{-3, 1, -2, 4, 0, -5, 7};
    removeNegatives(numbers);
    REQUIRE(numbers == std::vector<int>{1, 4, 0, 7});
}
