#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include <deque>

// templates3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the function max as a template
// function so that it could support generic inputs (vectors of both int and deque of double) 
// Use two generic types to accept both deque and vector.
// Use the keyword auto for the generic T returned by the function max

int max(const std::vector<int>& vec) {
    assert(("vec should not be empty", !vec.empty())); 

    int max_val = vec[0];
    for (const auto& v : vec) {
        if (v > max_val) {
            max_val = v;
        }
    }
    return max_val;
}


std::pair<int, double>  test_templates3() {
    std::vector<int> vec_i = {-4, 10, -2, 0, 3};
    std::deque<double> vec_d = {1.0e-1, 2.0, -4.0, 8.60};
    
    const int max_i = max(vec_i);
    const double max_d = max(vec_d);

    return {max_i, max_d};
}

#include <catch2/catch.hpp>

TEST_CASE("test_template3") {
    const std::pair<int, double> p = test_templates3();
    REQUIRE(p.first == 10);
    REQUIRE(p.second == 8.60);
}
