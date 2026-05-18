#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

// containers4.cpp
// Make me compile and pass the tests!

// std::stack<T> is a LIFO (last-in, first-out) container adapter.
// Key operations:
//   push(value)  — add to the top
//   top()        — inspect the top element (does not remove it)
//   pop()        — remove the top element
//   empty()      — true when the stack has no elements

// Step 1: Use std::ranges::for_each to push all words onto word_stack.
// Hint: std::ranges::for_each(words, [&word_stack](const auto& w){ word_stack.push(w); });
// Step 2: Pop words off one by one to fill the reversed vector (LIFO gives reverse order).

std::vector<std::string> reverseWords(const std::vector<std::string>& words) {
    std::stack<std::string> word_stack;

    // Fix: push all words onto word_stack using std::ranges::for_each
    std::ranges::for_each(words, ?);

    std::vector<std::string> reversed;
    while (!word_stack.empty()) {
        // Fix: append word_stack.top() to reversed, then pop
        ?
        ?
    }

    return reversed;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_containers4") {
    std::vector<std::string> words{"The", "quick", "brown", "fox", "jumps"};
    auto reversed = reverseWords(words);

    REQUIRE(reversed.size() == 5);
    REQUIRE(reversed[0] == "jumps");
    REQUIRE(reversed[1] == "fox");
    REQUIRE(reversed[2] == "brown");
    REQUIRE(reversed[3] == "quick");
    REQUIRE(reversed[4] == "The");
}
