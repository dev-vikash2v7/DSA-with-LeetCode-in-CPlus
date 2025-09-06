#include <iostream>
using namespace std;

class MyClass {
    int x, y, z;

public:
    // Constructor with no arguments
    MyClass() : MyClass(7 ) { // Delegates to parameterized constructor
        cout << "Default constructor called" << endl;
    }

    // Constructor with one argument
    MyClass(int val) : MyClass(val, 0, 0) { // Delegates to three-parameter constructor
        cout << "Single parameter constructor called " << val<< endl;
    }

    // Constructor with three arguments (main initialization constructor)
    MyClass(int a, int b, int c) : x(a), y(b), z(c) {
        cout << "Three-parameter constructor called with values: " << x << ", " << y << ", " << z << endl;
    }

    void display() {
        cout << "Values: x=" << x << ", y=" << y << ", z=" << z << endl;
    }
};

int main() {
    MyClass obj1;           // Calls default constructor
    // MyClass obj2(5);        // Calls single-parameter constructor
    // MyClass obj3(1, 2, 3);  // Calls three-parameter constructor directly

    // obj1.display();
    // obj2.display();
    // obj3.display();

    return 0;
}
