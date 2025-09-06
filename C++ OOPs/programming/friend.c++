// C++ program to illustrate how to access the private data
// members of the base class in derived class using public
// getter methods of base class
#include <iostream>
using namespace std;

class Derived ;

// Base class
class Base {
private:
    int privateVar;

public:

Base (int val) : privateVar(val){}

    // Constructor to initialize privateVar
   friend class Derived;

   void dis(){
    cout << privateVar << endl;
   }
};

// Derived class
class Derived  {
public:
   
    void modifyPrivateVar(Base &obj)

    {
     obj.privateVar = 5  ; 
    }
};

int main()
{
    // Create an object of Derived class
    Base b(2);
    Derived obj;

b.dis();
obj.modifyPrivateVar(b);
b.dis();
    // Display the initial value of privateVar

    

    return 0;
}
