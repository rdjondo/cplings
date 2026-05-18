#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <memory>

// ownership4.cpp
// Make me compile and pass the tests!
// Fix: the HolderBox alias uses a raw pointer (Holder*) which has no ownership semantics.
//      Replace it with std::unique_ptr<Holder> to express that each box owns exactly one Holder.
//      Also update push_data and test_ownership4 accordingly (use std::make_unique).

class ExpensiveResource {
private:
    static std::unordered_set< ExpensiveResource * > resources; // Keep track of all allocated instances of ExpensiveResource in memory
    std::string name;

public:
    static size_t getResourceCount() {
        return resources.size();
    };
    std::string getName() const {
        return name;
    }
    ExpensiveResource(std::string n = "") : name(n) {
        resources.insert(this);
        std::cout << "Opening Resource " << n << ", new count is:" << resources.size() << "\n";
    }
    ~ExpensiveResource() {
        resources.erase(this);
        std::cout << "Closing Resource " << name << ", new count is:" << resources.size() << "\n";
    }
};
std::unordered_set<ExpensiveResource *> ExpensiveResource::resources;

class Holder {
private:
    ExpensiveResource* resource;

public:
    std::string getName() const {
        return resource->getName();
    }
    Holder(std::string n = "") {
        resource = new ExpensiveResource(n);
    }
    ~Holder() {
        delete resource;
    }
};

using HolderBox = Holder*; // Note that HolderBox is a pointer to Holder. Modify this definition for using a unique resource

void push_data(std::vector<HolderBox> & holder_list, HolderBox hold_ptr) {
    holder_list.push_back(std::move(hold_ptr));
}

std::vector<HolderBox> test_ownership4() {
    const int num_elems = 3;
    std::vector<HolderBox> holder_list;
    for (size_t i = 0; i < num_elems; i++)
    {
        std::string s = "Hold#" + std::to_string(i);
        Holder h { s };
        // Try to pass unique ownership out of h to holder_list
        push_data(holder_list, &h);
    }
    return holder_list;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_ownership4_0") {
    std::vector<HolderBox> v = test_ownership4();
    std::cout << "\ntest_ownership1\n";
    std::cout << "The actual number of resources " << ExpensiveResource::getResourceCount() << "\n";
    std::cout << "The actual number of resources owned " << v.size() << "\n";

    REQUIRE(ExpensiveResource::getResourceCount() == 3);
    REQUIRE(ExpensiveResource::getResourceCount() == v.size());
    REQUIRE(v[0]->getName() == "Hold#0");
    REQUIRE(v[1]->getName() == "Hold#1");
    REQUIRE(v[2]->getName() == "Hold#2");
}

TEST_CASE("test_ownership4_1") {
    std::cout << "\ntest_ownership2\n";
    std::cout << "To avoid leaks the final number of resources should be 0 \n";
    std::cout << "The actual number of resources " << ExpensiveResource::getResourceCount() << "\n";
    REQUIRE(ExpensiveResource::getResourceCount() == 0);
}
