#include <iostream>
#include <cstdint> // Includes integer types
#include <vector>

// variables7.cpp
// Make me compile and pass the tests!
// Fix: set the value of each 'b' variable to match the expected test result.
// This exercise demonstrates integer overflow and type ranges.
// See https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
// See https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/

const int y = 10;
long long integer_char_sizes() {
    const char a = 10;
    const char b = ; // Fix: set expected value to pass the test
    std::cout << "Integer type = char \n";
    std::cout << "a=" << static_cast<int>(a) << "   b=" << static_cast<int>(b) << "\n";
    std::cout << "size of a=" << sizeof(a) << "  size of b=" << sizeof(b) << "\n\n";
    return  static_cast<long long>(b);
}

long long unsigned_integer_char_sizes() {
    const unsigned char a = 10;
    const unsigned char b = 0;  // Fix: set expected value to pass the test
    std::cout << "Integer type = char \n";
    std::cout << "a=" << static_cast<int>(a) << "   b=" << static_cast<int>(b) << "\n";
    std::cout << "size of a=" << sizeof(a) << "  size of b=" << sizeof(b) << "\n\n";
    return  static_cast<long long>(b);
}


long long integer_long_sizes() {
    const long a = 1'000; // The quote sign (') before the zeroes helps for readability but is not necessary
    const long b = 0;  // Fix: set expected value to pass the test
    std::cout << "Integer type = long \n";
    std::cout << "a=" << static_cast<int>(a) << "   b=" << static_cast<int>(b) << "\n";
    std::cout << "size of a=" << sizeof(a) << "  size of b=" << sizeof(b) << "\n\n";
    return b;
}

long long integer_int_sizes() {
    const int a = 1'000LL;
    const int b = 0;  // Fix: set expected value to pass the test
    std::cout << "Integer type = int \n";
    std::cout << "a=" << static_cast<long long>(a) << "   b=" << static_cast<long long>(b) << "\n";
    std::cout << "size of a=" << sizeof(a) << "  size of b=" << sizeof(b) << "\n\n";
    return b;
}

unsigned long long unsigned_integer_long_long_sizes() {
    std::cout << "Integer type = unsigned long long \n";
  const unsigned long long a = 10'000'000LL;
  const unsigned long long b = 0; // Fix: set expected value to pass the test
  std::cout << "a=" << static_cast<long long>(a) << "   b=" << static_cast<long long>(b) << "\n";
  std::cout << "size of a=" << sizeof(a) << "  size of b=" << sizeof(b) << "\n\n";
  return b;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("overflow_integer_sizes") {
    REQUIRE(integer_char_sizes() == -24);
    REQUIRE(unsigned_integer_char_sizes() == 232);
    REQUIRE(integer_long_sizes() == 80000);
    REQUIRE(integer_int_sizes() == 10'000'000);
    REQUIRE(unsigned_integer_long_long_sizes() == 18446744073699551616LLU);
}
