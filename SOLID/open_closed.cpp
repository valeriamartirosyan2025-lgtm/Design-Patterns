#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const vector<shared_ptr<Shape>>& shapes) const {
        double totalArea = 0;
        for (const auto& shape : shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    vector<shared_ptr<Shape>> shapes;
    shapes.push_back(make_shared<Circle>(5.0));
    shapes.push_back(make_shared<Rectangle>(4.0, 6.0));

    AreaCalculator calculator;
    cout << "Total area: " << calculator.calculateTotalArea(shapes) << endl;

    return 0;
}