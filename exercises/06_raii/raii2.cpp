#include <iostream>
#include <string>
#include <unordered_set>

// raii2.cpp
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
        std::cout << "Opening Resource " << n << ", new count is:"<< resources.size() << "\n";
    }
    ~ExpensiveResource() {
        resources. ...;   // Fix: perform an operation on resources
        std::cout << "Closing Resource " << name << ", new count is:" << resources.size() << "\n";
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
    ~Holder() { // The destructor releases the ExpensiveResource: this is the RAII pattern.
        delete resource;
    }
};


void test_raii2() {
    Holder hold1{ "First hold" };
    Holder hold2{ "First hold" }; // calling to hold same resource, the count should not change
    Holder hold3{ "Third hold" };
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_raii2") {
    test_raii2();
    std::cout << "To avoid leaks the final number of resources should be 0 \n";
    std::cout << "The actual number of resources " << ExpensiveResource::getResourceCount() << "\n";
    REQUIRE(ExpensiveResource::getResourceCount() == 0);
}
