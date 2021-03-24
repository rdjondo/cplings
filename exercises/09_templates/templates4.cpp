#include <iostream>
#include <vector>

// templates4.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the classes Animal and Cat as template classes.
// function so that it could support generic inputs (vectors of both int and deque of double) 
// Use two generic types to accept both deque and vector.
// Use the keyword auto for the generic int returned by the function max

template<typename ?>  // TODO : delete all references to typename and replace all int with int
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

#include <catch2/catch.hpp>

TEST_CASE("test_template4") {
    const std::pair<double, int> ages = test_templates4();
    REQUIRE(ages.first == ONE_YEAR_AND_HALF);
    REQUIRE(ages.second == INTEGER_FOUR_YEARS);
}
