#include <iostream>
#include <algorithm>
using namespace std;

string remove_duplicate(string s)
{
    if (s.empty())
        return "";

    char ch = s[0];
    cout << ch << endl;

    string ros = remove_duplicate(s.substr(1));
    cout << ch << "   " << ros << endl;

    if (ch == ros[0])
        return ros;

    return ch + ros;
}

int main()
{
    string s = "aaabbbccd";
    // sort(s.begin() , s.end());
    string result = remove_duplicate(s);
    cout << "result " << result << endl;
    return 0;
}