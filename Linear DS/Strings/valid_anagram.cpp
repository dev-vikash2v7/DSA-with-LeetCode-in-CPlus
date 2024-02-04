#include <iostream>

using namespace std;

bool isAnagram(string a, string b)
{
    int n1 = a.size();
    int n2 = b.size();

    if (n1 != n2)
        return false;

    int chars[256] = {0};

    for (int i = 0; i < n1; i++)
    {
        chars[a[i]]++;
        chars[b[i]]--;
    }


    for (int i = 0; i < n1; i++)
    {
        if (chars[a[i]] != chars[b[i]])
            return false;
    }

    return true;
}


int main()
{
    string a = "geksia",b = "geksib";

    isAnagram(a,b);
    return 0;
}