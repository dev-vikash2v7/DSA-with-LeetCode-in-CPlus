#include <bits/stdc++.h>
/*
product of array except for self
[1,2,3,4] -> [24, 12 , 8 , 6]
can contain negatives and zeros
*/

using namespace std;

void product(int arr[] , int n){

int left[n] , right[n] , product[n] ;

left[0] = 1 ; // left most element of left array is always 1
right[n-1] = 1 ;// right most element of right array is always 1

// traverse array from second index to end
// and store he product upto i-1 index from the start of array
for(int i = 1 ; i < n ; i++){
    left[i] = left[i-1] * arr[i-1] ;
}

// traverse array from second last to start
// and store he product upto i+1 index from the end of array
for(int i = n-2 ; i >=  0 ; i--){
    right[i] = right[i+1] * arr[i+1] ;
}

// traverse array from start  to end
// and store he product upto i+1 index from the end of array
for(int i = 0 ; i < n ; i++){
    product[i] = right[i] * left[i] ;
}


for(int i = 0 ; i <  n ; i++){
   cout << product[i] << " ";
}


}

int main()
{
int arr[] = {1,2,3,4};
int n = sizeof(arr)/4;
product(arr,n);

return 0;
}