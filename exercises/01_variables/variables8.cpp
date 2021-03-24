#include <iostream>
#include <cstdint> // Includes integer types
#include <vector>
#include <string>

#include <boost/safe_numerics/safe_integer.hpp>

// variables8.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 

// Try to find the constant values matching the expected results.
// This exercises showcases integer overflows. This occurs when the 
// selected datatype is not large enough to hold the value.
// See https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
// See: https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/

using namespace boost::safe_numerics;

std::vector<std::string> words;

//Hint: Use safe<> type from the safe_numerics (see more details in hint file)
uint32_t len; // This global variable keeps track of how may words should be accessed

// init_words is called one before test_danger_loop
void init_words(){
    words = { "Hello", "World", "!"};
    len = words.size(); // Only those 3 words should be accessed
}

const std::string secret_key = "Encrypted S3cr3t!";

std::string test_danger_loop(uint32_t  query_idx) { // Use safe<> type
    // Tip: if you cannot find the problem replace all uint32_t with 
    // safe<uint32_t>, from the boost::safe_numerics library
    // The safe<uint32_t> will throw an exception to help you find the bug

    words.push_back(secret_key); // Copies a secret at the end of the vector

    std::string response;
    if (len - query_idx > 0) { // Bound checking for protecting secret
        response = words.at(query_idx);
    }
    return response;
}

#include <catch2/catch.hpp>

TEST_CASE("integer_signedness") {
    // Initialize data
    const std::vector<std::string> expected_words { "Hello", "World", "!"};
    init_words();

    // Run loop
    for (size_t i = 0; i < expected_words.size(); i++)
    {
        std::cout << "Next index to query " << i << ", this is word: " << words[i] << "\n";
        REQUIRE(test_danger_loop(i) == expected_words.at(i));
    }
    
    std::cout << "Next index to query is dangerous :" << 4 << ", this is word:" << words[4] << "\n";
    REQUIRE(test_danger_loop(len + 1) == "");
}
