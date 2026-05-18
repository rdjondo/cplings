#include <iostream>
#include <vector>

// templates5.cpp
// Make me compile!
// Step 1: Make Repeater a template class with three parameters:
//   - T: the element type (e.g. int, char)
//   - V: the value to repeat (a non-type template parameter of type T)
//   - N: the number of repetitions (a non-type template parameter, e.g. size_t)
// Example usage: Repeater<int, 42, 5> creates a vector of five 42s.

template<?, ?, ?>  // Fix: replace '?' with typename T, T V, size_t N
class Repeater {
private:
    std::vector<?> v;
public:
    Repeater() {
        for (size_t i = 0; i < ?; i++)
        {
            v.push_back(?);
        }
    };
    const auto get() const {
        return v;
    };
};

std::vector<int> test_templates5_0() {
    Repeater<int, 42, 5> repeatInt;
    return repeatInt.get();
}

std::vector<char> test_templates5_1() {
    Repeater<char, 'A', 3> repeatChar;
    return repeatChar.get();
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_template5") {
    std::vector<int> repeatIntResult = test_templates5_0();
    std::vector<char> repeatCharResult = test_templates5_1();
    std::vector<int> repeatIntExpected {42, 42, 42, 42, 42};
    std::vector<char> repeatCharExpected {'A', 'A', 'A'};
    REQUIRE(repeatIntResult == repeatIntExpected);
    REQUIRE(repeatCharResult == repeatCharExpected);
}
