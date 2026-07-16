#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// threads5.cpp
// Make me pass the test! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out.

// Step 1: Make me pass the test. The consumer must wait until the producer
// has published a value. Busy-waiting wastes CPU and reading data_ready
// without the lock is a data race. Use the condition_variable to sleep
// until the producer notifies, then wake and read the value.

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
int shared_value = 0;

void producer() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_value = 42;
        data_ready = true;
    }
    cv.notify_one();
}

int consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    // Fix: wait on cv until data_ready is true, then read shared_value
    return shared_value;
}

int test_threads5() {
    std::thread p(producer);
    int result = consumer();
    p.join();
    return result;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_threads5") {
    REQUIRE(test_threads5() == 42);
}
