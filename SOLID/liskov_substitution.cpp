#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double getArea() const override {
        return side * side;
    }
};

void printShapeArea(const Shape& shape) {
    cout << "Area: " << shape.getArea() << endl;
}

int main() {
    Rectangle rect(4, 5);
    Square sq(4);

    printShapeArea(rect); 
    printShapeArea(sq);   

    return 0;
}