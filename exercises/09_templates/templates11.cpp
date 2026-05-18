#include <array>
#include <concepts>
#include <iostream>
#include <span>

// templates11.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts and std::span.

// std::span<T, N> is a lightweight, non-owning view of N contiguous elements of type T.
// When N is a compile-time constant (not std::dynamic_extent), you can branch on it
// with requires clauses evaluated at compile time.

// Step 1: Implement medianOfSorted() for an ODD number of elements.
// The median of a sorted range with N elements is the element at index N/2.
// Return a reference to that element.
template <typename T, std::size_t N>
    requires (N != 0 && N % 2 != 0)
T& medianOfSorted(std::span<T, N> s) {
    return ?;
}

// Step 2: Implement medianOfSorted() for an EVEN number of elements.
// The median is the average of the two middle elements: s[N/2 - 1] and s[N/2].
// Return the computed average by value.
template <typename T, std::size_t N>
    requires (N != 0 && N % 2 == 0)
T medianOfSorted(std::span<T, N> s) {
    return ?;
}


#include <catch2/catch.hpp>

TEST_CASE("test_templates11_odd_size") {
    std::array<int, 5> arr{1, 3, 5, 7, 9};
    REQUIRE(medianOfSorted(std::span<int, 5>{arr}) == 5);

    std::array<int, 3> arr3{2, 4, 6};
    REQUIRE(medianOfSorted(std::span<int, 3>{arr3}) == 4);

    std::array<int, 1> arr1{42};
    REQUIRE(medianOfSorted(std::span<int, 1>{arr1}) == 42);
}

TEST_CASE("test_templates11_even_size") {
    std::array<int, 4> arr{1, 3, 5, 7};
    REQUIRE(medianOfSorted(std::span<int, 4>{arr}) == 4); // (3 + 5) / 2

    std::array<int, 6> arr6{1, 2, 3, 4, 5, 6};
    REQUIRE(medianOfSorted(std::span<int, 6>{arr6}) == 3); // (3 + 4) / 2 = 3 (integer division)
}
