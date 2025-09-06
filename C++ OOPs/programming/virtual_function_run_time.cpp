#include <iostream>
using namespace std;

// Base class with virtual function
class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived classes
class Dog : public Animal {
public:
    void sound()  {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound()  {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Cat* a2 = new Cat();
    Animal* a3 = new Animal();

    a1->sound(); // Calls Dog::sound at runtime
    a2->sound(); // Calls Cat::sound at runtime
    a3->sound(); // Calls Cat::sound at runtime

    delete a1;
    // delete a2;
    delete a3;
    return 0;
}
