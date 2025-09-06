#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void func(string s) {

stack<char> s1;

for(char s:s) s1.push(s);

string rev ; 

while (!s1.empty())
{
    /* code */
    rev.push_back(s1.top());
    s1.pop();
}

cout <<rev <<endl;



}
int main()
{
 
 func("vikash");


    return 0;
}