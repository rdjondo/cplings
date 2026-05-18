#include <iostream>
#include <string>
#include <vector>

// lambdas1.cpp
// Make me compile and pass the tests!

// Step 1: Implement countStartingWith() using a lambda expression.
// The lambda should capture the words vector by reference ([&words] or [&]).
// It takes a char parameter and returns the number of words that begin with that character.
// Use a range-based for loop inside the lambda body.
//
// Syntax reminder:
//   auto myLambda = [capture](parameters) { body };

std::size_t countStartingWith(const std::vector<std::string>& words, char letter) {
    // Fix: define the lambda (capturing words) and call it with letter
    auto count = ?;
    return count(letter);
}


#include <catch2/catch.hpp>

TEST_CASE("test_lambdas1") {
    std::vector<std::string> words{"apple", "pear", "plum", "orange", "peach", "grape", "greengage"};

    REQUIRE(countStartingWith(words, 'p') == 3); // pear, plum, peach
    REQUIRE(countStartingWith(words, 'g') == 2); // grape, greengage
    REQUIRE(countStartingWith(words, 'a') == 1); // apple
    REQUIRE(countStartingWith(words, 'z') == 0);
}
