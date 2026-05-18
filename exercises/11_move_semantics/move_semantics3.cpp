#include <iostream>
#include <utility>

// move_semantics3.cpp
// Make me compile and pass the tests!

// A Handle wraps an integer resource identifier (like a file descriptor).
// Resources cannot be shared, so Handle must NOT be copyable.
// It MUST be movable so ownership can be transferred.

// Step 1: Delete the copy constructor and copy assignment operator (use = delete).
// Step 2: Implement the move constructor: transfer handle_ from other and set other.handle_ = -1.
// Step 3: Implement the move assignment operator similarly, but also release any existing resource first
//         (here, just printing a close message if handle_ != -1 before overwriting).

class Handle {
    int handle_;
public:
    explicit Handle(int h) : handle_(h) {
        std::cout << "Opened handle " << h << "\n";
    }

    ~Handle() {
        if (handle_ != -1)
            std::cout << "Closed handle " << handle_ << "\n";
    }

    // Fix: delete the copy constructor
    Handle(const Handle&) = ?;

    // Fix: delete the copy assignment operator
    Handle& operator=(const Handle&) = ?;

    // Fix: implement the move constructor — transfer handle_ and invalidate the source
    Handle(Handle&& other) noexcept : handle_(?) {
        other.handle_ = -1;
    }

    // Fix: implement the move assignment operator
    Handle& operator=(Handle&& other) noexcept {
        if (this != &other) {
            if (handle_ != -1)
                std::cout << "Closed handle " << handle_ << " (replaced)\n";
            handle_ = ?;
            other.handle_ = -1;
        }
        return *this;
    }

    int get() const { return handle_; }
    bool valid() const { return handle_ != -1; }
};


#include <catch2/catch.hpp>

TEST_CASE("test_move_semantics3_not_copyable") {
    static_assert(!std::is_copy_constructible<Handle>::value,
        "Handle must not be copy constructible");
    static_assert(!std::is_copy_assignable<Handle>::value,
        "Handle must not be copy assignable");
}

TEST_CASE("test_move_semantics3_move_constructor") {
    Handle h1(42);
    REQUIRE(h1.get() == 42);

    Handle h2(std::move(h1));
    REQUIRE(h2.get() == 42);
    REQUIRE(h1.get() == -1); // source is invalidated
}

TEST_CASE("test_move_semantics3_move_assignment") {
    Handle h1(7);
    Handle h2(99);

    h2 = std::move(h1);
    REQUIRE(h2.get() == 7);
    REQUIRE(h1.get() == -1);
}
