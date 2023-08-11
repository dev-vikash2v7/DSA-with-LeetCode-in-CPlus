#include <bits/stdc++.h>

using namespace std;


int const modulo = pow(10 , 9) + 7  ;


int fastpower(int a, int b){
    int res = 1;
    while (b > 0)
    {
        // if b is odd
        if (b & 1 == 1)
        {
            res = (res * a)%modulo;
        }
        a = a * a ;
        b = b >> 1 ; // b/2
    }
    return res ;
}

int main()
{
    int a = 2, b = 5;

    // cout << power(a, -b) << endl;
    cout << fastpower(a, b) << endl;
    return 0;
}


/* 
modulo properties =>
(a + b) % n  => ( a % n + b % n) % n ;
(5 + 7) % 2  => ( 5%2 + 7%2 ) % 2 => 0

(a * b) % n  => ( a % n - b % n) % n ;
(5 * 7) % 2  => ( 5%2 * 7%2 ) % 2 => 1

*/