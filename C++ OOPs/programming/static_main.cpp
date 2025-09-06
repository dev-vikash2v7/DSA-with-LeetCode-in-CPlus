#include <iostream>
using namespace std;

class MyClass {
public:
    static int staticVar;
    
    // Static method
    static void staticMethod() {
        cout << "Static method executed" << endl;
    }
};

// Initialize static variable
int MyClass::staticVar = [](){
    cout << "Static variable initialized" << endl;
    return 10;
}();

int main() {
    cout << "Main function started" << endl;
    MyClass::staticMethod(); // Calling static method
    return 0;
}
