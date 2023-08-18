#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int missingNumber(int arr[], int n)
{
   sort(arr , arr+n);
      int result = 1 ; 
      
        for(int i = 0 ; i < n ;i++){
            
            if(arr[i] == result){
              
             result++;
              
            }
        
        }
        
        return result ;
}

int main()
{
    int n;
    cin >> n;
    int A[5];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int a = missingNumber(A, n);
    cout << a;
    return 0;
}