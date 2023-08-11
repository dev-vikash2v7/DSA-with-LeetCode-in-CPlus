#include <iostream>
#include "Stack.hpp"

using namespace std;

void insertAtBottom(Stack &s , int elm){ // 20 10
    if(s.is_Empty()){
        s.push(elm);
            return ;
        }
        int x = s.pop();//20 
        cout <<"insertAtBottom "<<  elm << " " << x <<  endl; // 210 20 //210 10
        insertAtBottom(s , elm);
        s.push(x);
        s.show();
}

void reverse(Stack &s){
        // s.show();

        if(s.is_Empty()){
            return ;
        }
        int elm = s.pop();//2 0 210 10 20
        reverse(s);
        cout <<"reverse "<<  elm << endl; //20 10
        insertAtBottom(s, elm);
};

int main()
{
    Stack s(10);

s.push(20);
s.push(10);
s.push(210);
s.push(0);
s.push(2);

s.show();

reverse(s);

s.show();


return 0;
}