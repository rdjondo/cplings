#include <iostream>
#include <vector>

// templates4.cpp
// Make me compile!
// Step 1: Make me compile. Make Animal and Cat template classes.
// Replace each '?' with a template type parameter (e.g. T).
// T represents the numeric type used to store the animal's age (e.g. int, double).

template<typename ?>
class Animal {
private:
    ? age_;
public:
    Animal(int years) : age_(years) {};
    auto age() const { return age_; };
};

template<typename ?>
class Cat : public Animal<?> {
public:
    Cat(int years) : Animal<?>(years) {};
};

constexpr int    INTEGER_FOUR_YEARS = 4;
constexpr double ONE_YEAR_AND_HALF = 1.5;

std::pair<double, int>  test_templates4() {
    Cat blue(INTEGER_FOUR_YEARS);
    Cat sylvester(ONE_YEAR_AND_HALF);

    return { sylvester.age(), blue.age() };
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_template4") {
    const std::pair<double, int> ages = test_templates4();
    REQUIRE(ages.first == ONE_YEAR_AND_HALF);
    REQUIRE(ages.second == INTEGER_FOUR_YEARS);
}
