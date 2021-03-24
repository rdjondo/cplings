#include <iostream>
#include <string>

// raii1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile and pass the test!


class ExpensiveResource {
private:
    static int resources_count; // Keep count of all allocated instances of ExpensiveResource in memory
    std::string name;
public:
    static int getResourceCount() {
        return resources_count;
    };
    ExpensiveResource(std::string n = "") : name(n) {
        resources_count += 1;
        std::cout << "Opening Ressource " << name << ", new count is:"<< resources_count << "\n";
    }
    ~ExpensiveResource() {
        resources_count -= 1;
        std::cout << "Closing Ressource " << name << ", new count is:" << resources_count << "\n";
    }
};
int ExpensiveResource::resources_count = 0;

class Holder {
private:
    ExpensiveResource * resource;

public:
    Holder(std::string n = "") { 
        resource = new ExpensiveResource(n);
    }
    // Fix: I need a destructor that releases the resource
    ~
};


void test_raii1() {
    Holder hold1{ "First hold" };
    Holder hold2{ "Second hold" };
    Holder hold3{ "Third hold" };
}


#include <catch2/catch.hpp>

TEST_CASE("test_raii1") {
    test_raii1();
    std::cout << "To avoid leaks the final number of ressources should be 0 \n";
    std::cout << "The actual number of ressources " << ExpensiveResource::getResourceCount() << "\n";
    REQUIRE(ExpensiveResource::getResourceCount() == 0);
}
