#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// threads2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out.

// Step 1: Make me pass the test. Many threads increment the same counter.
// Without protection this is a data race (CWE-362) and the total is wrong.
// Protect the shared counter with the mutex so every increment is counted.

constexpr int NUM_THREADS = 8;
constexpr int INCREMENTS_PER_THREAD = 100000;

struct Counter {
    std::mutex mtx_;
    long value_ = 0;

    void increment() {
        // Fix: lock the mutex before touching value_
        value_ += 1;
    }
};

long test_threads2() {
    Counter counter;
    std::vector<std::thread> workers;
    for (int i = 0; i < NUM_THREADS; ++i) {
        workers.emplace_back([&counter]() {
            for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
                counter.increment();
            }
        });
    }
    for (auto& t : workers) {
        t.join();
    }
    return counter.value_;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_threads2") {
    REQUIRE(test_threads2() == NUM_THREADS * INCREMENTS_PER_THREAD);
}
