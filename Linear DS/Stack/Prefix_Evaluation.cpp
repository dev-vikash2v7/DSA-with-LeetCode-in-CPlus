#include <iostream>
#include <stack>

using namespace std;

int PrefixEvaluation(string prefix)
{
    stack<int> s;
    int result = -1;


    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        // operand
        if ('0' <= prefix[i] && prefix[i] <= '9')
        {
            s.push(prefix[i] - '0');
        }
        // operator
        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (prefix[i])
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
    string prefix = "-+7*45+20";
   cout << "result  " <<  PrefixEvaluation(prefix) << endl;;
    return 0;
}