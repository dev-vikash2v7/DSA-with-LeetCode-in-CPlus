#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int InfixEvaluation(string infix)
{
    stack<int> s;
    int result = -1;


    for (int i = infix.size() - 1; i >= 0; i--)
    {
        // operand
        if ('0' <= infix[i] && infix[i] <= '9')
        {
            s.push(infix[i] - '0');
        }
        // operator
        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (infix[i])
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
            // cout << result << endl;
        }
    }
    return result;
};

int main()
{
    string infix = "-+7*45+20";
   cout << "result  " <<  InfixEvaluation(infix) << endl;;
    return 0;
}