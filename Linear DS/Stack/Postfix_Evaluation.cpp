#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int PostfixEvaluation(string postfix)
{
    stack<int> s;
    int result = -1;


    for (int i = 0; i < postfix.size(); i++)
    {
        // operand
        if ('0' <= postfix[i] && postfix[i] <= '9')
        {
            s.push(postfix[i] - '0');
        }
        // operator
        else
        {
            int op2 = s.top();
            s.pop();

            int op1 = s.top();
            s.pop();

            switch (postfix[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            default:
                break;
            }

            s.push(result);
            cout << result << endl;
        }
    }
    return result;
};

int main()
{
    string postfix = "46+2/5*7+";
   cout << "result  " <<  PostfixEvaluation(postfix) << endl;;
    return 0;
}