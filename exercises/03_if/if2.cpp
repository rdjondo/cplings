#include <iostream>
#include <string>

// if2.cpp
// Make me compile and pass all tests!
// Step 1: The function returns nothing for "fuzz": add an else if branch for it.
// Step 2: Add a default return for any other input.


std::string fizz_if_foo(std::string fizzish) {
    if (fizzish == "fizz") {
        return "foo";
    }
    // Fix: add an 'else if' case for "fuzz" returning "bar", and a default return ""



}



#include <catch2/catch_test_macros.hpp>

TEST_CASE("foo_for_fizz") {
    REQUIRE(fizz_if_foo("fizz") == "foo");
}

TEST_CASE("bar_for_fuzz") {
    REQUIRE(fizz_if_foo("fuzz") == "bar");
}

TEST_CASE("default") {
    REQUIRE(fizz_if_foo("other") == "");
}
