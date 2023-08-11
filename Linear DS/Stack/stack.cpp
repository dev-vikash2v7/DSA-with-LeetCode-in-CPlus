#include "Stack.hpp"

int main()
{
    Stack  s(10);


    s.push( 34); 
    s.push( 3); 
    s.push( 4);     

    s.show();

    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
cout << "stack top " << s.stackTop() << endl ;
cout << "stack bottom " << s.stackBottom() << endl ;

//   s.show();

    if(s.is_Empty())     cout << "stack is empty\n";
    else     cout << "stack is not empty\n";             
     

    // delete s;                                                

return 0;
}