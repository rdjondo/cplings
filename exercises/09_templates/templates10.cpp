#include <concepts>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// templates10.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts.

// When multiple overloads of a function template are valid, the compiler picks
// the MOST CONSTRAINED one (the one with the strongest concept requirements).
// This lets you write efficient specialisations for richer iterator types.
//
// Concept hierarchy (most to least constrained):
//   std::random_access_iterator  →  supports iter + n in O(1)
//   std::bidirectional_iterator  →  supports --iter (but not + n)
//   std::input_or_output_iterator →  only supports ++iter

// Step 1: Implement my_advance for random-access iterators — use iter + n.
template <std::random_access_iterator Iter>
Iter my_advance(Iter iter, std::iter_difference_t<Iter> n) {
    return ?;
}

// Step 2: Implement my_advance for bidirectional iterators (but NOT random-access).
// Walk forward n steps (++iter) or backward n steps (--iter) in a loop.
template <std::bidirectional_iterator Iter>
Iter my_advance(Iter iter, std::iter_difference_t<Iter> n) {
    while (n > 0) { ?; --n; }
    while (n < 0) { ?; ++n; }
    return iter;
}

// Step 3: Implement my_advance for the base case (only forward movement supported).
template <std::input_or_output_iterator Iter>
Iter my_advance(Iter iter, std::iter_difference_t<Iter> n) {
    while (n > 0) { ?; --n; }
    return iter;
}


#include <catch2/catch.hpp>

TEST_CASE("test_templates10_random_access") {
    std::vector<int> v{1, 2, 3, 4, 5};
    auto it = my_advance(v.begin(), 3);
    REQUIRE(*it == 4);
}

TEST_CASE("test_templates10_bidirectional_forward") {
    std::list<int> lst{1, 2, 3, 4, 5};
    auto it = my_advance(lst.begin(), 2);
    REQUIRE(*it == 3);
}

TEST_CASE("test_templates10_bidirectional_backward") {
    std::list<int> lst{1, 2, 3, 4, 5};
    auto it = my_advance(lst.end(), -2);
    REQUIRE(*it == 4);
}
