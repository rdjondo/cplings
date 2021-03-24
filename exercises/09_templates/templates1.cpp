#include <iostream>
#include <tuple>
#include <vector>

// templates1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the function max as a template
// function so that it could support generic inputs (both int and double).
// Use a template parameter for the generic T returned by the function max.

int max(int i0, int i1) {
    if (i0 > i1) {
        return i0;
    }
    else {
        return i1;
    }
}


constexpr double ALMOST_EIGHT = 8.10;
constexpr double PI = 3.1415;

std::pair<int, double> test_templates1() {
    int i0 = -4;
    int i1 = 3;
    int max_i = max(i0, i1);

    double d0 = ALMOST_EIGHT;
    double d1 = PI;
    double max_d = max(d0, d1);

    return { max_i, max_d };
}

#include <catch2/catch.hpp>

TEST_CASE("test_templates1") {
    std::pair<int, double> p = test_templates1();
    REQUIRE(p.first == 3);
    REQUIRE(p.second == ALMOST_EIGHT);
}
