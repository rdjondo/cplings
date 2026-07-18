#include <iostream>
#include <future>
#include <thread>

// threads4.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Sometimes a worker thread must hand a result
// back to the caller. std::promise carries the value and std::future
// receives it. Set the promise value from inside the worker.

int slow_square(int value) {
    return value * value;
}

int test_threads4() {
    std::promise<int> result_promise;
    std::future<int> result_future = result_promise.get_future();

    std::thread worker([&result_promise]() {
        int squared = slow_square(7);
        // Fix: deliver the computed value through the promise
    });

    int result = result_future.get();
    worker.join();
    return result;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_threads4") {
    REQUIRE(test_threads4() == 49);
}
