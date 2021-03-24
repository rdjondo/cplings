#include <iostream>
#include <vector>
#include <string>

// templates7.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the class Repeater a template class.
// function so that it could support generic inputs (vectors of both int and deque of double) 
// Use two generic types to accept both deque and vector.
// Use the keyword auto for the generic T returned by the function max


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
    // TODO : Delete test and content of if condition
    if constexpr ( ...? /* check if the type is a pointer */) {
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



#include <catch2/catch.hpp>

TEST_CASE("test_template6") {
    test_templates7_0();
    test_templates7_1();
}
