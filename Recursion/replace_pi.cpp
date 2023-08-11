#include <iostream>

using namespace std;

string result;
string replace(string s)
{

    if (s.empty())
        return "";

    if (s[0] == 'p' && s[1] == 'i')
    {
        result.append("3.14");
        replace(s.substr(2));
    }
    else
    {

        string p(1, s[0]);
        string i(1, s[1]);

        result.append(p);
        result.append(i);
        
        replace(s.substr(1));
        
    }

    return result;
}

int main()
{

    string s = "pippxxppiixipi";

    cout << replace(s) << endl;

    return 0;
}