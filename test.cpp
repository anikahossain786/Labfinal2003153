#include "pch.h"
#include "gtest/gtest.h"
#include <string>

class Shape {
public:
	virtual ~Shape() = default;
   virtual double calculateArea() const = 0;
    virtual std::string getType() const = 0;
};
class Circle : public Shape {
    public:
    Circle(double radius) : radius(radius) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
    std::string getType() const override {
        return "Circle";
    }
private:
	double radius;
};
class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : width(width), height(height) {}
	double calculateArea() const override {
		return width * height;
	}
	std::string getType() const override {
		return "Rectangle";
	}
private:
	double width;
	double height;
};

class square : public Shape {
public:
	square(double side) : side(side) {}
	double calculateArea() const override {
		return side * side;
	}
	std::string getType() const override {
		return "Square";
	}
private:
	double side;
};
// === Unit Tests ===

TEST(ShapeTest, CircleArea) {
	Circle circle(5);
	EXPECT_DOUBLE_EQ(circle.calculateArea(), 78.53975);
	EXPECT_EQ(circle.getType(), "Circle");
}

TEST(ShapeTest, RectangleArea) {
	Rectangle rectangle(4, 5);
	EXPECT_DOUBLE_EQ(rectangle.calculateArea(), 20);
	EXPECT_EQ(rectangle.getType(), "Rectangle");
}

TEST(ShapeTest, SquareArea) {
	square square(4);
	EXPECT_DOUBLE_EQ(square.calculateArea(), 16);
	EXPECT_EQ(square.getType(), "Square");
}
TEST(ShapeTest, CircleType) {
	Circle circle(5);
	EXPECT_EQ(circle.getType(), "Circle");
}
TEST(ShapeTest, RectangleType) {
	Rectangle rectangle(4, 5);
	EXPECT_EQ(rectangle.getType(), "Rectangle");
}
TEST(ShapeTest, SquareType) {
	square square(4);
	EXPECT_EQ(square.getType(), "Square");
}
TEST(ShapeTest, CircleAreaNegative) {
	Circle circle(1);
	EXPECT_DOUBLE_EQ(circle.calculateArea(), 3.14159);
	EXPECT_EQ(circle.getType(), "Circle");
}
TEST(ShapeTest, RectangleAreaNegative) {
	Rectangle rectangle(4, 6);
	EXPECT_DOUBLE_EQ(rectangle.calculateArea(), 24);
	EXPECT_EQ(rectangle.getType(), "Rectangle");
}
 TEST(ShapeTest, SquareAreaNegative) {
    square square(4);
    EXPECT_DOUBLE_EQ(square.calculateArea(), 16);
    EXPECT_EQ(square.getType(), "Square");
}

