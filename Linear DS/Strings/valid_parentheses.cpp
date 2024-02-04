#include <iostream>
#include <vector>

using namespace std;

bool valid(string s)
{
    vector<char> parenthese;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (parenthese.empty())
            parenthese.push_back(s[i]);

        else if ((parenthese.back() == '(' && s[i] == ')') || (parenthese.back() == '[' && s[i] == ']') || (parenthese.back() == '{' && s[i] == '}'))
            parenthese.pop_back();

        else
            parenthese.push_back(s[i]);
    }
    if (!parenthese.empty())
        return false;

    return true;
}

int main()
{
    string s = ")";

    if (valid(s))
        cout << "valid\n";
    else
        cout << "not valid\n";
    return 0;
}