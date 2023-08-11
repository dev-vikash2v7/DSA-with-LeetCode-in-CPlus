#include <bits/stdc++.h>

using namespace std;

void substrings(string s, int n, int i, string new_string)
{
    if (i == n)
    {
        cout << new_string << endl;
        return;
    }
    string a = new_string;
    a.push_back(s[i]);

    substrings(s, n, i + 1, a);
    substrings(s, n, i + 1, new_string);
}

int main()
{
    string s = "abc";
    int n = 3;

    substrings(s, n, 0, " ");

    return 0;
}