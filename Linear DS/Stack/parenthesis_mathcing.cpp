#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int main()
{
    stack<char> parenthesis_list;

    // string e = "{ ( [ ( (3 * 9 ) + 1 ) / [2 - (2 / 4) ] ] * 67  ) }" ;
    string e = "1 ) + (";
    // remove(e.begin() , e.end() , ' ')  ;

    bool correct = true;
    // [ ( , ( , )]
    for (int i = 0; i < e.length(); i++)
    {

        if (e[i] == '[' || e[i] == '(' || e[i] == '{')
        {
            parenthesis_list.push(e[i]);
        }
        else if (e[i] == ']' || e[i] == ')' || e[i] == '}')
        {
            if (parenthesis_list.empty())
            {
                correct = false;
                break;
            };
            parenthesis_list.pop();
        }
    }

    if (correct && parenthesis_list.empty())
        cout << "correct expression\n";
    else
        cout << "Incorrect expression\n";

    return 0;
}