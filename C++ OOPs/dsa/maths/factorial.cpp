#include <iostream>
#include <vector>
using namespace std;

int func(int n) {

 if(n == 0) return 1 ;

 return n * func(n-1) ;
}

// optimized
int func2(int n) {

long long res = 1 ; 

for(int i = 2  ; i <= n ; i++){
    res *= i ;
}
return res;
}


int main()
{
    int n = 5;
    
cout <<  func(n);

    return 0;
}