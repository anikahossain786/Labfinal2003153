#include <bits/stdc++.h>
#include <cmath>  
using namespace std;
class Shape {
public:
    virtual ~Shape() {}
    virtual double calculateArea() const = 0;
    virtual string getType() const = 0;
};


// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius; 
    }
     string getType() const override {
        return "Circle";
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height; 
    }
      string getType() const override {
        return "Rectangle";
    }
};

// Square class
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
    std::string getType() const override {
        return "Square";
    }
};


class ShapeFactory {
public:
    virtual ~ShapeFactory() {}
    virtual Shape* createShape() const = 0;
};



// Factory for Circle
class CircleFactory : public ShapeFactory {
public:
    double radius;

public:
    CircleFactory(double r) : radius(r) {}
    Shape* createShape() const override {
        return new Circle(radius);
    }
};

// Factory for Rectangle
class RectangleFactory : public ShapeFactory {
public:
    double width, height;

public:
    RectangleFactory(double w, double h) : width(w), height(h) {}
    Shape* createShape() const override {
        return new Rectangle(width, height);
    }
};

// Factory for Square
class SquareFactory : public ShapeFactory {
public:
    double side;

public:
    SquareFactory(double s) : side(s) {}
    Shape* createShape() const override {
        return new Square(side);
    }
};

void ClientCode(const ShapeFactory& factory) {
    Shape* shape = factory.createShape();
     cout << "Shape: " << shape->getType() << "\n";
     cout << "Area: " << shape->calculateArea() << "\n";
    delete shape;
}

int main() {
   
    CircleFactory circleFactory(5);
    ClientCode(circleFactory);

    cout << endl;

    
    RectangleFactory rectangleFactory(4, 7);
    ClientCode(rectangleFactory);

    cout << endl;

    
    SquareFactory squareFactory(3);
    ClientCode(squareFactory);

    return 0;
}
