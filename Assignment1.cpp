#include <iostream>
#include <cmath>
using namespace std;

// Base Class
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void calculateArea() const = 0; // Pure virtual
    virtual ~Shape() {
        cout << "Destructor called for " << name << endl;
    }
};

// Derived Class - Rectangle
class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : Shape("Rectangle"), length(l), breadth(b) {}

    void calculateArea() const override {
        cout << "Area of Rectangle: " << (length * breadth) << endl;
    }
};

// Derived Class - Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void calculateArea() const override {
        cout << "Area of Circle: " << (M_PI * radius * radius) << endl;
    }
};

// Derived Class - Triangle
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}

    void calculateArea() const override {
        cout << "Area of Triangle: " << (0.5 * base * height) << endl;
    }
};

// Main Function
int main() {
    const int size = 3;
    Shape* shapes[size];

    shapes[0] = new Rectangle(4.0, 5.0);
    shapes[1] = new Circle(3.0);
    shapes[2] = new Triangle(4.0, 6.0);

    for (int i = 0; i < size; i++) {
        shapes[i]->calculateArea();
    }

    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    return 0;
}
