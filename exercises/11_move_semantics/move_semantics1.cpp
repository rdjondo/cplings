#include <algorithm>
#include <iostream>
#include <utility>

// move_semantics1.cpp
// Make me compile and pass the tests!

// Step 1: The Buffer class manages a heap-allocated integer array.
// The copy constructor, copy assignment operator, and destructor are already provided.
// Add a move constructor and a move assignment operator.
// After moving, set the source's data_ to nullptr and size_ to 0
// so the destructor safely does nothing (delete[] nullptr is a no-op).

class Buffer {
    int* data_;
    std::size_t size_;
public:
    explicit Buffer(std::size_t n) : data_(new int[n]{}), size_(n) {}

    Buffer(const Buffer& other) : data_(new int[other.size_]), size_(other.size_) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    ~Buffer() { delete[] data_; }

    // Fix: implement the move constructor
    // It should transfer data_ and size_ from other, then set other.data_ = nullptr, other.size_ = 0
    Buffer(Buffer&& other) noexcept : data_(?), size_(?) {
        other.data_ = nullptr;
        other.size_ = 0;
    }

    // Fix: implement the move assignment operator
    // Free the current data_, transfer from other, then invalidate other
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = ?;
            size_ = ?;
            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    std::size_t size() const { return size_; }
    int* data() const { return data_; }
};


#include <catch2/catch.hpp>

TEST_CASE("test_move_semantics1_move_constructor") {
    Buffer original(4);
    for (std::size_t i = 0; i < 4; ++i)
        original.data()[i] = static_cast<int>(i + 1);

    int* original_ptr = original.data();
    Buffer moved(std::move(original));

    REQUIRE(moved.size() == 4);
    REQUIRE(moved.data() == original_ptr); // same pointer — no heap allocation
    REQUIRE(moved.data()[0] == 1);
    REQUIRE(moved.data()[3] == 4);
    REQUIRE(original.size() == 0);
    REQUIRE(original.data() == nullptr);
}

TEST_CASE("test_move_semantics1_move_assignment") {
    Buffer src(3);
    src.data()[0] = 99;
    int* src_ptr = src.data();

    Buffer dest(1);
    dest = std::move(src);

    REQUIRE(dest.size() == 3);
    REQUIRE(dest.data() == src_ptr);
    REQUIRE(dest.data()[0] == 99);
    REQUIRE(src.size() == 0);
    REQUIRE(src.data() == nullptr);
}
