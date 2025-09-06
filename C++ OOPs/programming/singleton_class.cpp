#include <iostream>
using namespace std;

class Singleton {

static Singleton *instance  ;

Singleton(){
    cout << "process instance create"<<endl;

     
}
public:

    static Singleton *createInstance(){
        if(instance == nullptr){
            instance = new Singleton();
            cout << "Single instance created"<<endl;
        }
        else{
            cout << "No Single instance created"<<endl;
        }
        
    }
};

// Initialize static member of Singleton class
Singleton *Singleton :: instance = nullptr;

int main() {

    Singleton* obj1 = Singleton::createInstance();
    Singleton* obj2 = Singleton::createInstance();

    if(obj1 == obj2){
        cout << "both instance are same" <<endl;
    }
   
}
