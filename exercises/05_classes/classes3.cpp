#include <iostream>
#include <string>

// classes3.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Write the Circle constructor

struct Point {
    double x;
    double y;

    bool operator==(const Point& p) const{
        return std::abs(x - p.x)<1e-6 && std::abs(y - p.y) < 1e-6;
    }
};

constexpr Point point_zero = { 0.0, 0.0 };

class Shape {
protected:
    Point center_;

public:
    Shape(const Point & centre = point_zero) : center_(centre) { }

    Point center() const {
        return point_zero;
    }
};


class Circle : public Shape {
public:
    Circle(const Point& centre = point_zero) { } // Fix: add a Call to parent constructor

    Point center() const {
        return center_;
    }
};


#include <catch2/catch.hpp>

TEST_CASE("test_zero_parent") {
    Shape shape;
    Circle circle;
    REQUIRE(shape.center() == point_zero);
    REQUIRE(circle.center() == point_zero);
}

TEST_CASE("test_one_parent") {
    Point point_in{ 1.0, 1.0 };
    Circle circle(point_in);
    REQUIRE(circle.center() == point_in);
}

TEST_CASE("test_two_parent") {
    Point point_in{ 2.0, 2.0 };
    Circle circle(point_in);
    REQUIRE(circle.center() == point_in);
}
