#include "StackLinkedList.hpp"

int main()
{
    StackLinkedList  s;

    s.push( 34); 
    s.push( 3); 
    s.push( 4);     


    cout <<"pop : "<< s.pop() << endl;
    cout <<"pop : "<< s.pop() << endl;
    s.display();
    cout <<"pop : "<< s.pop() << endl;
    // cout << s.pop() << endl;
// cout << "stack top " << s.stackTop() << endl ;
// cout << "stack bottom " << s.stackBottom() << endl ;


    if(s.isEmpty())     cout << "stack is empty\n";
    else     cout << "stack is not empty\n";             
     

    // delete s;                                                

return 0;
}