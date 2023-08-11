#include <bits/stdc++.h>

using namespace std;

int a;
int path[4][4] = {0};

int func(int n, int m)
{

    if (n == 1 || m == 1)
    {
        return 1;
    }
    if (path[n][m] != 0 || path[m][n] != 0)
    {
        return path[n][m];
    }
    else
    {
        path[n][m] = a;
    }
    a = func(n - 1, m) + func(n, m - 1);
    return a ;
}

int main()
{
    int arr[] = {};

    cout << func(4, 3) << endl;
    ;
    // a= 0;
    // cout << func(3, 3) << endl;
    // ;
    // a = 0 ;
    cout << func(2, 2) << endl;
    ;
    a = 0 ;
    cout << func(3, 4) << endl;
    a = 0 ;
    ;
    cout << func(3, 2) << endl;
    a = 0 ;
    ;
    cout << func(2, 3) << endl;
    ;

    return 0;
}