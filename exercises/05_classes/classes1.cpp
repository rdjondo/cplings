#include <iostream>

// classes1.cpp
// Make me compile and pass the tests!
// Fix 1 (Bird): set number_legs to the correct value in the Bird constructor.
// Fix 2 (Cat): remove the redundant 'bool has_fur = true;' class member: it shadows
//              the inherited Animal::has_fur and should be set in the constructor only.

class Animal {
protected:
    int number_legs = 0; // protected so only accessible by Bird and Cat

public:
    bool has_fur = false;  // public so only accessible by any user, and also Bird and Cat
    int get_number_legs() {
        return this->number_legs;
    }
};

class Bird : public Animal{
public:
    Bird() { // Bird constructor
        // Fix: set number_legs to the correct value for a bird
        number_legs = ;
    }
    int get_number_legs() {
        return this->number_legs;
    }
};

class Cat : public Animal {
public:
    Cat() {  // Cat constructor
        number_legs = 4;
        has_fur = true;
    }
    bool has_fur = true; // Fix: remove this line: it shadows Animal::has_fur
    int get_number_legs() {
        return this->number_legs;
    }
};


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_legs") {
    Cat c;
    Bird b;
    Animal a;
    std::cout << "Generic animal has " << a.get_number_legs() << " legs\n";
    std::cout << "A cat has " << c.get_number_legs() << " legs\n";
    std::cout << "A bird has " << b.get_number_legs() << " legs\n";
    REQUIRE(c.get_number_legs() == 4);
    REQUIRE(b.get_number_legs() == 2);
}

TEST_CASE("test_fur") {
    Cat c;
    Bird b;
    Animal a;
    std::cout << "Generic animal has fur = " << a.has_fur << " \n";
    std::cout << "A cat has fur = " << c.has_fur << "\n";
    std::cout << "A bird has fur = " << b.has_fur << "\n";
    REQUIRE(c.has_fur != b.has_fur);
}
