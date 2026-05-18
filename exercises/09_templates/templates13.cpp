#include <concepts>
#include <forward_list>
#include <iostream>
#include <ranges>
#include <vector>

// templates13.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts and ranges.

// Step 1: Define a concept Averagable<T> requiring that type T supports:
//   - Addition: x + y produces a T (or convertible to T)
//   - Division by integer: x / 2 is valid
// These two operations are needed to compute (lo + hi) / 2 for the even-size median.
// Hint: requires(const T x, const T y) { x + y; x / 2; }

template <typename T>
concept Averagable = ?;

// Step 2: Implement median_of_sorted() for any forward range of Averagable elements.
// - For an ODD number of elements N, return the element at position N/2.
// - For an EVEN number of elements N, return (element[N/2 - 1] + element[N/2]) / 2.
// Use std::ranges::distance to get the size, then advance an iterator.

template <std::ranges::forward_range Range>
    requires Averagable<std::ranges::range_value_t<Range>>
auto median_of_sorted(Range&& range) {
    auto n = std::ranges::distance(range);
    auto it = std::ranges::begin(range);

    if (n % 2 != 0) {
        // Fix: advance it by n/2 and return the element
        std::advance(it, ?);
        return *it;
    } else {
        std::advance(it, n / 2 - 1);
        auto lo = *it++;
        auto hi = *it;
        // Fix: return the average of lo and hi
        return ?;
    }
}


#include <catch2/catch.hpp>

TEST_CASE("test_templates13_concept") {
    static_assert(Averagable<int>);
    static_assert(Averagable<double>);
}

TEST_CASE("test_templates13_odd") {
    std::vector<int> v{1, 3, 5, 7, 9};
    REQUIRE(median_of_sorted(v) == 5);
}

TEST_CASE("test_templates13_even") {
    std::vector<int> v{2, 4, 6, 8};
    REQUIRE(median_of_sorted(v) == 5); // (4 + 6) / 2
}

TEST_CASE("test_templates13_forward_list") {
    std::forward_list<int> fl{1, 2, 3, 4, 5};
    REQUIRE(median_of_sorted(fl) == 3);
}
