#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ownership5.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Let fill_vec borrow the input vector to
// permanently modify it;


// Display value for a vector
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& collection) {
    out << "{";
    if (collection.size() > 0) {
        const auto it_begin = collection.begin();
        const auto it_before_end = collection.end() - 1;
        auto it = it_begin;
        for (; it != it_before_end; it++) {
            out << static_cast<T>(*it) << ", ";
        }
        out << static_cast<T>(*it);
    }
    out << "}";
    return out;
}


void fill_vec(std::vector<int> vec) { // Fix: fix type here
    vec->push_back(22);
    vec->push_back(44);
    vec->push_back(66);
}


std::unique_ptr<std::vector<int>> test_ownership5() {
    std::unique_ptr<std::vector<int>> vec = std::make_unique<std::vector<int>>();
    vec->push_back(11);
    fill_vec(vec. ...?); // Fix: obtain pointer from vec
    vec->push_back(88);

    return std::move(vec);
}

#include <catch2/catch.hpp>

TEST_CASE("test_ownership5") {
    std::cout << "\ntest_ownership5\n";
    const auto vec = test_ownership5();
    std::cout << "vec has length of " << vec->size() << " content " << *vec << "\n";
    REQUIRE(vec->size() == 5);
}
