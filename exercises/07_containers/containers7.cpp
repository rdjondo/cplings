#include <algorithm>
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>

// containers7.cpp
// Make me compile and pass the tests!

// std::ranges::iota(range, start)  (C++23, <numeric>)
//   Fills a range with consecutive values: start, start+1, start+2, ...
//
// std::ranges::fold_left(range, init, binary_op)  (C++23, <algorithm>)
//   Equivalent to std::accumulate: combines all elements left-to-right using binary_op.
//   Example: fold_left({1,2,3}, 0, std::plus<>{}) == 6

// Step 1: Use std::ranges::iota to fill a vector with values 1, 2, ..., n.
std::vector<int> makeRange(int n) {
    std::vector<int> result(static_cast<std::size_t>(n));
    std::ranges::iota(result, ?); // Fix: what start value gives 1, 2, ..., n?
    return result;
}

// Step 2: Use std::ranges::fold_left to compute the average of a non-empty vector.
// Return std::nullopt if the vector is empty.
// Hint: use std::plus<>{} as the binary operation, and cast the sum to double before dividing.
std::optional<double> average(const std::vector<int>& numbers) {
    if (numbers.empty()) return std::nullopt;
    auto sum = std::ranges::fold_left(numbers, ?, ?); // Fix: initial value and binary op
    return static_cast<double>(sum) / static_cast<double>(numbers.size());
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_containers7_iota") {
    REQUIRE(makeRange(5) == std::vector<int>{1, 2, 3, 4, 5});
    REQUIRE(makeRange(1) == std::vector<int>{1});

    auto r10 = makeRange(10);
    REQUIRE(r10.size() == 10);
    REQUIRE(r10[0] == 1);
    REQUIRE(r10[9] == 10);
}

TEST_CASE("test_containers7_average") {
    REQUIRE(average({1, 2, 3, 4, 5}).value() == 3.0);
    REQUIRE(average({10, 20}).value() == 15.0);
    REQUIRE(average({7}).value() == 7.0);
    REQUIRE(!average({}).has_value());
}
