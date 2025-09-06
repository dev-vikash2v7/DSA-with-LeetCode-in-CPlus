#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void func(string s) {

stack<char> stk;

for(char a : s){

if(a == '(' || a=='[' || a=='{'){
    stk.push(a);
}
else if (stk.empty()) {
        cout << "Not valid parenthesis" << endl;
    return ;
}
else{
  char top = stk.top();
            if ((a == ')' && top == '(') ||
                (a == '}' && top == '{') ||
                (a == ']' && top == '[')) {
                stk.pop(); 
            } 
    else{
        cout << "Not valid parenthesis" << endl;
        return ;
    }
}
}
        cout << " valid parenthesis" << endl;
}
int main()
{
 
 func("()");

    return 0;
}