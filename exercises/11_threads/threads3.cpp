#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

// threads3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out.

// Step 1: Make me pass the test. A mutex is not the only tool for shared
// state. For a single counter, an atomic is lock-free and simpler.
// Make the counter safe to increment from many threads without a mutex.

constexpr int NUM_THREADS = 8;
constexpr int INCREMENTS_PER_THREAD = 100000;

long test_threads3() {
    long counter = 0; // Fix: change the type so concurrent increments are safe
    std::vector<std::thread> workers;
    for (int i = 0; i < NUM_THREADS; ++i) {
        workers.emplace_back([&counter]() {
            for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
                counter++;
            }
        });
    }
    for (auto& t : workers) {
        t.join();
    }
    return counter;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_threads3") {
    REQUIRE(test_threads3() == NUM_THREADS * INCREMENTS_PER_THREAD);
}
