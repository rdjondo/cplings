#include <iostream>

// classes2.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out. 

// Step 1: Make me compile!
// Write the Circle constructor

struct Point {
    double x;
    double y;

    bool operator==(const Point& p) const{
        return std::abs(x - p.x) < 1e-6 && std::abs(y - ) < ;
    }
};

constexpr Point point_zero = ; 

class Shape {
public:
    Point center() const {
        return point_zero;
    }

    double area() const {
        return 0.0;
    }
};


class Circle : public Shape {
private:
    Point center_;
    double radius_;

public:
    static const double pi;

    Circle(const Point & centre = point_zero, double radius = 0.0) : center_(centre), radius_(radius) { // Default center_ is in zero
    }

    Point center() const {
        return center_;
    }

    double area() const {
        return 0.0;
    }
};

const double Circle::pi = 3.1415926535;


#include <catch2/catch.hpp>

TEST_CASE("test_zero") {
    Shape shape;
    Circle circle;
    REQUIRE(shape.center() == point_zero);
    REQUIRE(circle.center() == point_zero);
}

TEST_CASE("test_one") {
    Point point_in{ 1.0, 1.0 };
    Circle circle(point_in);
    REQUIRE(circle.center() == point_in);
}

TEST_CASE("test_two") {
    Point point_in{ 2.0, 2.0 };
    double radius = 3.0;
    Circle circle(point_in, radius);
    REQUIRE(circle.center() == point_in);
    REQUIRE(circle.area() == Circle::pi * radius * radius);
}

