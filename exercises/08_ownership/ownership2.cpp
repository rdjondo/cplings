#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// ownership2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Move ownership of data in vec0 to vec1;


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
        out << *it ;
    }
    out << "}";
    return out;
}


std::vector<int> fill_vec(std::vector<int> && vec) {
    vec.push_back(22);
    vec.push_back(44);
    vec.push_back(66);

    return   ...? vec;
}


std::pair<std::vector<int>, std::vector<int>> test_ownership2() {
    std::vector<int> vec0 = {};
    vec0.push_back(11);
    auto vec1 = fill_vec( ...? vec0);
    vec1.push_back(88);

    std::cout<< "vec0 has length "<< vec0.size() << " content "<< vec0 <<"\n";
    std::cout << "vec1 has length " << vec1.size() << " content " << vec1 << "\n";
    return { vec0, vec1 };
}

#include <catch2/catch.hpp>

TEST_CASE("test_ownership2") {
    std::cout << "\ntest_ownership2\n";
    auto [vec0, vec1] = test_ownership2();
    REQUIRE(vec0.size() == 0);
    REQUIRE(vec1.size() == 5);
}
