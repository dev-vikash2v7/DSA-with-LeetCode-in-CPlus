#include <iostream>
#include <stack>

using namespace std;

int Reduntant_Parenthesis(string exp)
{
    stack<char> s;

    for (int i = 0; i < exp.size(); i++)
    {

        if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-' || exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (s.top() == '(')
            {
                return true;
            }
            while (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')
            {
                s.pop();
            }
        }
    }
    return false;
}

int main()
{
    string exp = "( a + (a+b) )";
    cout << "result  " << Reduntant_Parenthesis(exp) << endl;

    return 0;
}