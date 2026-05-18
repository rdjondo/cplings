#include <functional>
#include <iostream>
#include <string>
#include <vector>

// lambdas5.cpp
// Make me compile and pass the tests!

// std::function<Ret(Args...)> stores any callable (lambda, function pointer, functor)
// with the given signature. This enables the observer / callback pattern:
// an object collects a list of callbacks and fires them all on an event.

// Step 1: Add a private member to EventSource to store the callbacks.
//         Use: std::vector<std::function<void(const std::string&)>>
// Step 2: Implement registerCallback() to append the callback to the list.
// Step 3: Implement fire() to call every registered callback with the message.

class EventSource {
    // Fix: add a member to store callbacks
    ?

public:
    void registerCallback(std::function<void(const std::string&)> cb) {
        // Fix: store cb
        ?
    }

    void fire(const std::string& message) {
        // Fix: invoke every stored callback with message
        ?
    }
};


#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_lambdas5") {
    EventSource source;

    std::vector<std::string> received;
    source.registerCallback([&received](const std::string& msg) {
        received.push_back(msg);
    });

    std::size_t count = 0;
    source.registerCallback([&count](const std::string&) {
        ++count;
    });

    source.fire("hello");
    source.fire("world");

    REQUIRE(received.size() == 2);
    REQUIRE(received[0] == "hello");
    REQUIRE(received[1] == "world");
    REQUIRE(count == 2);
}
