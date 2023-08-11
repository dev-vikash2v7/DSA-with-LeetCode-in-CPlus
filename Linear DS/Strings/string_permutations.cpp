#include <bits/stdc++.h>

using namespace std;

void swap(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
};

void permutation(string s, int i , int n)
{
    if (i  == n-1)
    {
        cout << s << endl;
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(s[i], s[j]);
        cout <<"before " << i << " " << j << " " << s << endl;  
        permutation(s,  i + 1 , n);
        cout <<"after " << i << " " << j <<  " " << s  <<endl;  
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "012";
    int n = 3;

    permutation(s, 0, n);

    return 0;
}

/*
abc

abc
acb

bac
bca

cab
cba


                                            abc

                        abc                bac           cab
                    abc     acb        bac     bca    cab      cba


                                            012

                        012                102           201
                    012     021       102      120    201      210


*/