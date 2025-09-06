#include <iostream>
using namespace std;

// Base Class
class A {
public:
    A() {
        cout << "Constructor of A\n";
    }
    void show() {
        cout << "Method of A\n";
    }
};

// Intermediate Classes with virtual inheritance
class B  :virtual public A{
public:
    B() {
        cout << "Constructor of B\n";
    }
//    void show(){
// cout << " B show"<<endl;
//     }
};

class C  :virtual public A {
public:
    C() {
        cout << "Constructor of C\n";
    }
//      void show(){
// cout << " C show"<<endl;
//     }
};

// Derived Class
class D : public B, public C {
public:
    D() {
        cout << "Constructor of D\n";
    }
   
};

int main() {
    D obj;
    obj.show();  // Calls A's show() without ambiguity
    return 0;
}
