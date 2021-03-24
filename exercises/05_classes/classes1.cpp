#include <iostream>

// classes1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Write the constructor so that legs and fur have the right values for Cat and Bird

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
        // Fix:  Please redefine here the class variables inherited from the Animal class
        number_legs = ;
    }
    int get_number_legs() {
        return this->number_legs;
    }
};

class Cat : public Animal {
public:
    Cat() {  // Cat constructor
        // TODO: Delete next 2 variables. Please define the class variables inherited from the Animal class
        number_legs = 4;
        has_fur = true;
    }
    bool has_fur = true;
    int get_number_legs() {
        return this->number_legs;
    }
};


#include <catch2/catch.hpp>

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
