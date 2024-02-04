// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(string arr[], int N)
{
    string ans = "";
    int max_c = 0;

    for (int i = 0; i < N; i++)
        max_c = max(max_c, (int) arr[i].size());
    

    for (int i = 0; i < max_c; i++)
    {

        for (int j = 0; j < N; j++)
        {

            char ch = arr[j][j];

            // if (==)
            // {
            // }
        }
    }
    return "-1";
}

int main()
{

    string arr[2] = {"geek", "geenote"};

    return 0;
}