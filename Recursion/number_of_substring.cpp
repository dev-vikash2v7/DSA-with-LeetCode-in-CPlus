#include <iostream>

using namespace std;

void substrings(string str, string sub)
{
    if (str.empty())
    {
        cout << sub << endl;
        return;
    };

    char ch = str[0];

    string ros = str.substr(1);
    cout << str << endl;

    cout << ch << " + " << ros << endl;

    substrings(ros, sub + ch);

    cout << ch << " - " << ros << endl;

    substrings(ros, sub);

    cout << ch << " * " << ros << endl;

}

int main()
{
    string s = "ABC";
    substrings(s, "");

    return 0;
}