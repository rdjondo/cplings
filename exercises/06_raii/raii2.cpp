#include <iostream>
#include <string>
#include <unordered_set>

// raii1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile and pass the test! Here a set is used to avoid creating more resources when the same name is used


class ExpensiveResource {
private:
    static std::unordered_set<std::string> resources; // Keep track of all allocated instances of ExpensiveResource in memory
    std::string name;
public:
    static size_t getResourceCount() {
        return resources.size();
    };
    ExpensiveResource(std::string n = "") : name(n) {
        resources. ...;   // Fix: perform an operation on resources
        std::cout << "Opening Ressource " << n << ", new count is:"<< resources.size() << "\n";
    }
    ~ExpensiveResource() {
        resources. ...;   // Fix: perform an operation on resources
        std::cout << "Closing Ressource " << name << ", new count is:" << resources.size() << "\n";
    }
};
std::unordered_set<std::string> ExpensiveResource::resources;

class Holder {
private:
    ExpensiveResource * resource;

public:
    Holder(std::string n = "") { 
        resource = new ExpensiveResource(n);
    }
    ~Holder() { // TODO: Delete the destructor
        delete resource;
    }
};


void test_raii1() {
    Holder hold1{ "First hold" };
    Holder hold2{ "First hold" }; // calling to hold same resource, the count should not change
    Holder hold3{ "Third hold" };
}


#include <catch2/catch.hpp>

TEST_CASE("test_raii1") {
    test_raii1();
    std::cout << "To avoid leaks the final number of ressources should be 0 \n";
    std::cout << "The actual number of ressources " << ExpensiveResource::getResourceCount() << "\n";
    REQUIRE(ExpensiveResource::getResourceCount() == 0);
}
