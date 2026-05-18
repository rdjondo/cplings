#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

// lambdas2.cpp
// Make me compile and pass the tests!

// Lambda expressions can be passed directly as comparators to std::ranges::sort.
// The ranges version takes the container directly — no need for begin()/end().
// A comparator lambda takes two parameters (x, y) and returns true if x should come before y.

// Step 1: Sort letters case-insensitively using std::ranges::sort and a lambda comparator.
// Hint: std::tolower(x) converts a char to lowercase.
std::vector<char> sortCaseInsensitive(std::vector<char> letters) {
    std::ranges::sort(letters, ?);
    return letters;
}

// Step 2: Sort integers by absolute value using std::ranges::sort and a lambda comparator.
// Hint: std::abs(x) returns the absolute value.
std::vector<int> sortByAbsoluteValue(std::vector<int> numbers) {
    std::ranges::sort(numbers, ?);
    return numbers;
}


#include <catch2/catch.hpp>

TEST_CASE("test_lambdas2_case_insensitive") {
    std::vector<char> letters{'C', 'd', 'a', 'z', 't', 'S', 'p', 'm'};
    auto sorted = sortCaseInsensitive(letters);
    // Expected order (case-insensitive): a, C, d, m, p, S, t, z
    REQUIRE(std::tolower(sorted[0]) == 'a');
    REQUIRE(std::tolower(sorted[1]) == 'c');
    REQUIRE(std::tolower(sorted[2]) == 'd');
    REQUIRE(std::tolower(sorted[7]) == 'z');
}

TEST_CASE("test_lambdas2_absolute_value") {
    std::vector<int> nums{-10, 3, -1, 7, -5};
    auto sorted = sortByAbsoluteValue(nums);
    // Expected order by |x|: -1, 3, -5, 7, -10
    REQUIRE(sorted[0] == -1);
    REQUIRE(sorted[1] == 3);
    REQUIRE(sorted[2] == -5);
    REQUIRE(sorted[3] == 7);
    REQUIRE(sorted[4] == -10);
}
