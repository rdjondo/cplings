#include <iostream>

// functions5.cpp
// Make me compile!
// Fix 1: is_even has the wrong return type: a constexpr function that returns a bool
//        cannot be declared void. Fix the return type and use trailing return type syntax.
// Fix 2: the lambda is missing its parameter. A lambda takes the form:
//        [captures](params) -> ReturnType { body }

constexpr void is_even(int num) {
    return num % 2 == 0;
}

// A lambda function: [captures](params) -> ReturnType { body }
auto sale_price = []() -> int {
    if (is_even(price))
        return price - 10;
    else
        return price - 3;

};

int function_syntax() {
    auto original_price = 51;
    auto final_price = sale_price(original_price);
    std::cout << "Your sale price is " << final_price << "\n";
    return final_price;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("function_syntax") {
  REQUIRE(function_syntax() == 48);
}
