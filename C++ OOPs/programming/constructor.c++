#include <iostream>
using namespace std;

class MyClass {
    int x;

public:
    MyClass() : x(0) { // Default constructor
        cout << "Default constructor called" << endl;
    }

    MyClass(int val) : x(val) { // Parameterized constructor
        cout << "Parameterized constructor called with value: " << x << endl;
    }

    MyClass(const MyClass &obj) { // Copy constructor
        x = obj.x;
        cout << "Copy constructor called" << endl;
    }

    // MyClass(MyClass&& obj) noexcept : x(obj.x) { // Move constructor
    //     obj.x = 0;
    //     cout << "Move constructor called" << endl;
    // }

    int getValue() const {
        return x;
    }
};

int main() {
    MyClass obj1;                 // Calls default constructor
    MyClass obj2(10);             // Calls parameterized constructor
    MyClass obj3 = obj2;          // Calls copy constructor
    MyClass obj4 = MyClass(20);   // Calls move constructor

    cout << "obj1 value: " << obj1.getValue() << endl;
    cout << "obj2 value: " << obj2.getValue() << endl;
    cout << "obj3 value: " << obj3.getValue() << endl;
    cout << "obj4 value: " << obj4.getValue() << endl;

    return 0;
}
