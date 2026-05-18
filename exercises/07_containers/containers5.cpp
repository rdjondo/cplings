#include <iostream>
#include <map>
#include <string>
#include <vector>

// containers5.cpp
// Make me compile and pass the tests!

// std::map<Key, Value> stores key-value pairs sorted by key.
// Accessing a key that doesn't exist with operator[] default-constructs the value.
// Iterating over a map yields std::pair<const Key, Value> elements.

// Step 1: Group each word by its first character.
// For every word in words, insert it into groups under the key word[0].
// Hint: groups[word[0]].push_back(word)  automatically creates the vector if missing.

std::map<char, std::vector<std::string>> groupByFirstLetter(const std::vector<std::string>& words) {
    std::map<char, std::vector<std::string>> groups;

    for (const auto& word : words) {
        // Fix: insert word into groups under the key of its first character
        ?
    }

    return groups;
}


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_containers5") {
    std::vector<std::string> words{"apple", "avocado", "banana", "blueberry", "cherry", "apricot"};
    auto groups = groupByFirstLetter(words);

    REQUIRE(groups.size() == 3);
    REQUIRE(groups['a'].size() == 3); // apple, avocado, apricot
    REQUIRE(groups['b'].size() == 2); // banana, blueberry
    REQUIRE(groups['c'].size() == 1); // cherry

    REQUIRE(groups['a'][0] == "apple");
    REQUIRE(groups['b'][0] == "banana");
    REQUIRE(groups['c'][0] == "cherry");
}
