#include <bits/stdc++.h>

using namespace std;

void bitrep(int n)
{
    if (n == 0 || n == 1)
    {
        cout << n;
        return;
    }
    bitrep(n / 2);
    cout << n % 2;
}

void getbit(int n, int i)
{
    // int a = i;
    // while (i--)
    // {
    //     cout << n << " -> ";
    //     bitrep(n);
    //     n = n >> 1;
    //     cout << endl;
    // }
    //   cout << n << " => " ;  bitrep(n);

    int mask = 1 << i ;
    cout << "bit at " << i << " index is "  << ((mask & n) == 0  ? 0 : 1) <<  endl ;
    //  bitrep(mask);
    //  cout << endl;
    //  bitrep(mask & n);
}

void setbit(int n, int i)
{
    n  = n | (1 << i);
    getbit(n , i ) ;


}
void clearbit(int n, int i)
{
      n  = n & ~(1 << i);
    getbit(n , i ) ;
}

int main()
{
    int n = 53;
    int i = 5;

    bitrep(n);
    cout << endl;

    getbit(n, i);

    setbit(n, i);

    clearbit(n,i);

    return 0;
}