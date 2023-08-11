#include <iostream>

using namespace std;

int main()
{
    int arr[] = {5,2,6,1,4,7,3,6};
    int n = 8 ; 
    int profit = 0 ;

    for(int i = 1 ; i < n ;i++){
        if(arr[i] > arr[i-1]){
            profit += ( arr[i] - arr[i-1] );
        }
    }
    cout << profit << endl;
return 0;
}