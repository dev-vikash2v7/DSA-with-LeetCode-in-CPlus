#include <iostream>

using namespace std;

string result;
int i = 0 ;
string reverse(string s)
{
    if (s.empty())
        return "";

    reverse(s.substr(1));

    // cout << s[0];

    string a(1 , s[0]) ;
    result.append( a );


    return result;
}

int main()
{
    string s = "123456";
    cout << reverse(s) << endl;
    return 0;
}