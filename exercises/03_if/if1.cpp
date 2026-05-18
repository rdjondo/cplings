#include <iostream>

// if1.cpp
// Make me compile and pass the tests!

int bigger(int a, int b) {
    // Complete this function to return the bigger number!
    // Do not use:
    // - another function call
    // - additional variables

}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("ten_is_bigger_than_eight") {
    REQUIRE(bigger(10, 8) == 10);
}

TEST_CASE("fortytwo_is_bigger_than_thirtytwo") {
    REQUIRE(bigger(42, 32) == 42);
}
