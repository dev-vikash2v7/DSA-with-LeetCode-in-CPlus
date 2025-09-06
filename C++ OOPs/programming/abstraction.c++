#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
     double area() {}; 

    virtual void display() {
        cout << "This is a shape." << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the pure virtual function
    double area()  {
        return length * width;
    }

    void display() override {
        cout << "This is a rectangle." << endl;
    }
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the pure virtual function
    double area()  {
        return 3.14159 * radius * radius;
    }

    void display() override {
        cout << "This is a circle." << endl;
    }
};

int main() {
    Shape* shape1 = new Rectangle(10, 5);
    Shape* shape2 = new Circle(7);

    shape1->display();
    cout << "Area: " << shape1->area() << endl;

    shape2->display();
    cout << "Area: " << shape2->area() << endl;

    delete shape1;
    delete shape2;

    return 0;
}
