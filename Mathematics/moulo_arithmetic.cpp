#include <bits/stdc++.h>

using namespace std;

// given number n . print factorial 
// constraint 1 <= N <= N
// print answer in modulo M where M = 47
// result % M is always less than M
// means that M is maximum value that computer can store
// 10^9 + 7 - very close to integer maximum
/*
 (a * b) % m =   ( (a % m) + (b % m)) % m ;

 (1* 2*3*4*5)  % 47
 (1* 2*3*4)%47 * 5%45)  % 47
 (1* 2*3*4)%47 * 5%45)  % 47
*/

void fact(int n){

long long fac = 1 ;
int modulo =pow(10 , 9) + 7  ;

for(int i = 2 ; i <= n ; i++){
    fac =( fac * i) % modulo ;
}

cout << fac  << endl;;
}

int main()
{
int n = 20;
fact(n);

return 0;
}

/* 
modulo properties =>
(a + b) % m  => ( (a % m) + (b % m)) % m ;
(5 + 7) % 2  => ( 5%2 + 7%2 ) % 2 => 0

(a * b) % n  => ( (a % m) * (b % m)) % m ;
(5 * 7) % 2  => ( 5%2 * 7%2 ) % 2 => 1

(a - b) % n  => ( (a % m) - (b % m) + m) % m ;
(5 * 7) % 2  => ( 5%2 * 7%2 ) % 2 => 1

(a / b) % n  => ( (a % m) * (1/b)  % m ;
(5 * 7) % 2  => ( 5%2 * 7%2 ) % 2 => 1



*/