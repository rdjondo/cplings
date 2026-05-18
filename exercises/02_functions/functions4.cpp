#include <iostream>

// functions4.cpp
// Make me compile!
// Fix: sale_price has the wrong return type and is missing trailing return type syntax.
// It should return an int using the trailing return type: auto sale_price(int price) -> int

bool is_even(int num) {
    return num % 2 == 0;
}

void sale_price(int price){
    if (is_even(price)) {
        return price - 10;
    }
    else {
        return price - 3;
    }
}

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
