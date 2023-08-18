#include <iostream>

using namespace std;

string removeConsecutives(string s)
{
    if (s.empty())
        return "";

    string ros = s.substr(1, s.size());

    if (s[0] == ros[0])
       return removeConsecutives(ros);

    else
    {
        int i = 1;
        for (; i < s.size(); i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
      return  removeConsecutives(s);
    };
}

int main()
{
    string s = "aabb";
  cout <<   removeConsecutives(s) << endl;

    return 0;
}