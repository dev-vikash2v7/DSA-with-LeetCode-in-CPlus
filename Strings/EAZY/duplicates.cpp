#include <iostream>

using namespace std;

void duplicates(string s)
{
    int chars[256] = {0};

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        chars[s[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (chars[s[i]] > 1){
            cout << s[i] << endl;
            chars[s[i]] = 0 ;
        }
    }
}

int main()
{
    string s = "vikviksh";
    duplicates(s);
    return 0;
}