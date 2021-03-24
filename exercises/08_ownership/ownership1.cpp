#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// ownership1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Let fill_vec borrow the input vector to
// permanently modify it; References are a nice way of borrowing a variable.


// Display value for a vector
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& collection) {
    out << "{";
    if (collection.size() > 0) {
        const auto it_begin = collection.begin();
        const auto it_before_end = collection.end() - 1;
        auto it = it_begin;
        for (; it != it_before_end; it++) {
            out << *it << ", ";
        }
        out << *it;
    }
    out << "}";
    return out;
}


void fill_vec(std::vector<int> vec) {
    vec.push_back(22);
    vec.push_back(44);
    vec.push_back(66);
}


std::vector<int> test_ownership1() {
    std::vector<int> vec = {};
    vec.push_back(11);
    fill_vec(vec);
    vec.push_back(88);

    std::cout << "vec has length " << vec.size() << " content " << vec << "\n";
    return vec;
}

#include <catch2/catch.hpp>

TEST_CASE("test_ownership1") {
    std::cout << "\ntest_ownership1\n";
    const auto vec = test_ownership1();
    REQUIRE(vec.size() == 5);
}
