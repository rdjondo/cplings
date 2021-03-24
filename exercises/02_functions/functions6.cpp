#include <iostream>
#include <string>

// functions6.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Step 1: Make me compile and pass!

int value = 1;

namespace my_namespace_0 {
    int value = 2;
}

int called(int value) {
    {
        int value = 8;
        std::cout << "In local scope of function called: value=" << value << "\n";
    }
    std::cout << "In function called: value=" << value << "\n";
    return value;
}


int my_function() {

    std::cout << "In global scope: value=" << value << "\n";
    {
        int value = 8;
        std::cout << "In my_function scope: value=" << value << "\n";
        std::cout << "In my_function scope, using global: value=" << ::value << "\n";
    }
    std::cout << "In namespace my_namespace_0 scope: value=" << my_namespace_0::value << "\n";

    int value = called(10);
    std::cout << "Returned out of function called() : value=" << value << "\n";
    
    return value +  + ; // Fix: must return the sum of global scope and output of called() and value of namespace my_namespace_0
}

#include <catch2/catch.hpp>

TEST_CASE("learn_scope") {
    REQUIRE(my_function() == 13);
}
