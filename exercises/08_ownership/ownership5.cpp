#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ownership5.cpp
// Make me compile and pass the tests!
// Fix 1: fill_vec takes std::vector<int> by value: change the parameter type to
//        std::vector<int>* so it can modify the vector through a raw pointer.
// Fix 2: use vec.get() to obtain the raw pointer from the unique_ptr when calling fill_vec.


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

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_ownership5") {
    std::cout << "\ntest_ownership5\n";
    const auto vec = test_ownership5();
    std::cout << "vec has length of " << vec->size() << " content " << *vec << "\n";
    REQUIRE(vec->size() == 5);
}
