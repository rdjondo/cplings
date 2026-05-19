#include <optional>
#include <string>
#include <variant>

// variants2.cpp
// Make me compile and pass the tests!

// std::get_if<T> returns a T* if v holds T, or nullptr otherwise.
// It never throws. Use it when the active type is uncertain.
//
// Step 1: Pass the correct argument to std::get_if (it takes a pointer to the variant).
// Step 2: In isNonEmpty(), dereference the pointer to call .empty() on the string.

using Payload = std::variant<int, std::string, double>;

std::optional<int> safeGetInt(const Payload& v) {
    if (const auto* p = std::get_if<int>(?)) { // Fix: pass the address of v
        return *p;
    }
    return std::nullopt;
}

bool isNonEmpty(const Payload& v) {
    const auto* s = std::get_if<std::string>(&v);
    return s != nullptr && !?->empty(); // Fix: dereference s to call .empty()
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_variants2_safeGetInt") {
    Payload p = 7;
    REQUIRE(safeGetInt(p).value() == 7);

    p = std::string("hi");
    REQUIRE(!safeGetInt(p).has_value());

    p = 3.14;
    REQUIRE(!safeGetInt(p).has_value());
}

TEST_CASE("test_variants2_isNonEmpty") {
    Payload p = std::string("hello");
    REQUIRE(isNonEmpty(p));

    p = std::string("");
    REQUIRE(!isNonEmpty(p));

    p = 42;
    REQUIRE(!isNonEmpty(p));
}
