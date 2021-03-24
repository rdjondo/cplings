#include <iostream>

// functions4.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

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

#include <catch2/catch.hpp>

TEST_CASE("function_syntax") {
  REQUIRE(function_syntax() == 48);
}
