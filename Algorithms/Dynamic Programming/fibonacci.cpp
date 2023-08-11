#include <bits/stdc++.h>

using namespace std;



//bottom-up approch
// int fib(int n)  
// {  
//     if(n==0 || n==1) return n;

//     int A[2];  

//     A[0] = 0, A[1] = 1;  

//     for( int i=2; i<n; i++)  
//     {  
//         int t = A[1];
//          A[1] = A[0] + A[1] ; 
//          A[0] = t;
//     }  
//     return A[1];  
// }  


//bottom-up approch
int count_ = 0;
vector<int> memo;

int fib(int n) {
    if (memo[n] != -1)
        return memo[n];
    
    count_++;
    
    if (n < 0)
        throw invalid_argument("Invalid input: n cannot be negative.");
    
    if (n == 0)
        return 0;
    
    if (n == 1){
        cout<<"count : "<< count_ << endl;
        return 1;
    }
    
    int sum = fib(n - 1) + fib(n - 2);
    memo[n] = sum;
    
    return sum;
}

int main()
{
int n = 6 ;
memo.resize(n + 1, -1);
cout << fib(n)<< endl;


return 0;
}