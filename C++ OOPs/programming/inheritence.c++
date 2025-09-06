#include <iostream>

using namespace std;



class Base{

    public:
        int id_b;
        void printID_b(){
            cout << "Base Id " << id_b <<endl;
        };
};

class Child : public Base{

public:
     int id_c;
    void printID_c()
    {
        id_b = 5 ;
        cout << "Child ID: " << id_c << endl;
        cout << "Child Base ID: " << id_b << endl;
    }

};

int main(){

     Child obj1;

    // the child class object.
    obj1.id_b = 7;
    obj1.printID_b();

    obj1.id_c = 91;
    obj1.printID_c();
    obj1.printID_b();

}