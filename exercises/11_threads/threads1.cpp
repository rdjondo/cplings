#include <iostream>
#include <thread>
#include <vector>

// threads1.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Launch worker on its own std::thread,
// then wait for it to finish before reading the result.
// A thread that is never joined nor detached terminates the program.

void worker(int input, int& output) {
    output = input * 2;
}

int test_threads1() {
    int result = 0;
    std::thread t(worker, 21, ); // Fix: pass the missing argument so worker can write to result
    // Fix: wait for the thread to finish here
    return result;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_threads1") {
    REQUIRE(test_threads1() == 42);
}
