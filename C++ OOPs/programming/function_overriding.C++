// C++ program for function overriding with data members
#include <bits/stdc++.h>
using namespace std;

//  base class declaration.
class Animal {
public:
    string  color = "Black";
      void virtual move(){
        cout << "Animal can move" <<endl;
    }
};

// inheriting Animal class.
class Dog : public Animal {
public:
    string color = "Grey";
    void  move () {
        cout << "Dog can move" <<endl;
    };
};

// Driver code
int main(void)
{
    
    Animal *d = new Dog(); // accessing the field by reference
    Animal d1 =  Dog(); // accessing the field by reference
    
                      // variable which refers to derived
    cout << d->color << endl;
    cout << d1.color << endl;

    d->move();
    d1.move();
}
