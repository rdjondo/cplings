#include <iostream>
#include <vector>
#include <string>

// templates7.cpp
// Make me compile!
// Step 1: Complete the show() function.
// Replace '...?' with the compile-time condition that checks whether C is a pointer.
// Hint: use is_pointer<C>::value inside the if constexpr condition.


template<typename C, C v> // Value holder
struct constant_holder {
    static constexpr C value = v;
};

using true_type = constant_holder<bool, true>;
using false_type = constant_holder<bool, false>;


template<typename T> // Value is false if is not specializing pointer
struct is_pointer : false_type {};

template<typename T> // Value is true if specializing pointer
struct is_pointer<T*> : true_type {};

// Use 'if constexpr (is_pointer<C>::value) { } else { } to output
// the dereferenced pointer or the value if it's not a pointer
template<typename C>
void show(C data) {
    if constexpr ( ...? /* Fix: check if C is a pointer type using is_pointer<C>::value */) {
        std::cout << *data << "\n";
    }
    else {
        std::cout << data << "\n";
    }
}

void test_templates7_0() {
    const char val = 'A';
    show(val);
}
void test_templates7_1() {
    const char val = 'B';
    show(&val);
}



#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_template7") {
    test_templates7_0();
    test_templates7_1();
}
