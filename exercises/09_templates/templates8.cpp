#include <concepts>
#include <iostream>
#include <string>

// templates8.cpp
// Make me compile and pass the tests!
// Note: This exercise uses C++20 concepts.

// A concept is a named Boolean predicate on template parameters.
// It constrains which types a template may be instantiated with.
//
// Syntax for a requires-expression concept:
//   template <typename T>
//   concept MyConcept = requires(T value) { expression_that_must_be_valid; };

// Step 1: Define a concept Printable that requires an expression (std::cout << t)
// to be well-formed for a const T& named t.
// Hint: requires(const T& t) { std::cout << t; }

template <typename T>
concept Printable = ?;

// Step 2: Constrain the print() function template to only accept Printable types.
// Replace 'typename T' with 'Printable T' in the template parameter list.

template <typename T>
void print(const T& value) {
    std::cout << value << "\n";
}

struct NotPrintable {};


#include <catch2/catch.hpp>

TEST_CASE("test_templates8_concept") {
    static_assert(Printable<int>);
    static_assert(Printable<double>);
    static_assert(Printable<std::string>);
    static_assert(!Printable<NotPrintable>);

    print(42);
    print(3.14);
    print(std::string{"hello"});
}
