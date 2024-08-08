#include <iostream>
#include <string>

// if2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Step 2: Get the bar_for_fuzz and default_to_baz tests passing (see expected values at bottom of the file)!


std::string fizz_if_foo(std::string fizzish) {
    if (fizzish == "fizz") {
        return "foo";
    }
    // Fix: Make new "else if" and "else" cases to pass the test


    
}



#include <catch2/catch.hpp>

TEST_CASE("foo_for_fizz") {
    REQUIRE(fizz_if_foo("fizz") == "foo");
}

TEST_CASE("bar_for_fuzz") {
    REQUIRE(fizz_if_foo("fuzz") == "bar");
}
