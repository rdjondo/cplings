#include <algorithm>
#include <iostream>
#include <utility>

// move_semantics4.cpp
// Make me compile and pass the tests!

// std::exchange(obj, new_val) atomically sets obj = new_val and returns the OLD value of obj.
// It is ideal for implementing move operations because it transfers a value and
// leaves the source in a valid (null/zero) state in a single expression.
//
// Example: int* p = std::exchange(other.ptr_, nullptr);
//          This sets other.ptr_ to nullptr and gives you the original pointer.
//
// Step 1: Complete the move constructor using std::exchange for both data_ and size_.
// Step 2: Complete the move assignment operator the same way.

class DynArray {
    int* data_;
    std::size_t size_;
public:
    explicit DynArray(std::size_t n) : data_(new int[n]{}), size_(n) {}

    DynArray(const DynArray& other) : data_(new int[other.size_]), size_(other.size_) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    DynArray& operator=(const DynArray& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    ~DynArray() { delete[] data_; }

    // Fix: use std::exchange to implement the move constructor in the initializer list
    DynArray(DynArray&& other) noexcept
        : data_(std::exchange(other.data_, ?))
        , size_(std::exchange(other.size_, ?))
    {}

    // Fix: use std::exchange to implement the move assignment operator
    DynArray& operator=(DynArray&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = std::exchange(other.data_, ?);
            size_ = std::exchange(other.size_, ?);
        }
        return *this;
    }

    std::size_t size() const { return size_; }
    int* data() const { return data_; }
};


#include <catch2/catch.hpp>

TEST_CASE("test_move_semantics4_move_constructor") {
    DynArray a(5);
    for (std::size_t i = 0; i < 5; ++i)
        a.data()[i] = static_cast<int>(i * 3);

    int* a_ptr = a.data();
    DynArray b(std::move(a));

    REQUIRE(b.size() == 5);
    REQUIRE(b.data() == a_ptr);
    REQUIRE(b.data()[2] == 6);
    REQUIRE(a.size() == 0);
    REQUIRE(a.data() == nullptr);
}

TEST_CASE("test_move_semantics4_move_assignment") {
    DynArray a(3);
    a.data()[0] = 7;
    int* a_ptr = a.data();

    DynArray b(1);
    b = std::move(a);

    REQUIRE(b.size() == 3);
    REQUIRE(b.data() == a_ptr);
    REQUIRE(b.data()[0] == 7);
    REQUIRE(a.data() == nullptr);
    REQUIRE(a.size() == 0);
}
