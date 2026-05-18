#include <algorithm>
#include <array>
#include <concepts>
#include <iostream>
#include <ranges>
#include <vector>

// templates12.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts and ranges.

// std::ranges::range   — a type with begin() and end()
// std::ranges::sized_range — a range that also has a size() in O(1)
// Combining standard concepts lets you express precise constraints.

// Step 1: Define a concept SizedRange that requires the type R to satisfy BOTH
//   std::ranges::range  AND  std::ranges::sized_range.
// Hint: SizedRange = std::ranges::range<R> && std::ranges::sized_range<R>;

template <typename R>
concept SizedRange = ?;

// Step 2: Implement find_min() using std::ranges::min_element.
// Dereference the returned iterator to get the value.
template <SizedRange R>
auto find_min(const R& range) {
    return ?;
}

// Step 3: Implement find_max() using std::ranges::max_element.
template <SizedRange R>
auto find_max(const R& range) {
    return ?;
}


#include <catch2/catch.hpp>

TEST_CASE("test_templates12_concept") {
    static_assert(SizedRange<std::vector<int>>);
    static_assert(SizedRange<std::array<double, 4>>);
    static_assert(!SizedRange<int>);
}

TEST_CASE("test_templates12_min_max") {
    std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};
    REQUIRE(find_min(v) == 1);
    REQUIRE(find_max(v) == 9);

    // Values chosen as exact IEEE 754 fractions (no rounding issues)
    std::array<double, 4> arr{2.5, 1.0, 3.5, 0.5};
    REQUIRE(find_min(arr) == 0.5);
    REQUIRE(find_max(arr) == 3.5);
}
