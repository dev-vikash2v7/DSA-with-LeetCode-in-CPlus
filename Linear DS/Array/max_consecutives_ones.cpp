#include <iostream>

using namespace std;

void max_consecutivee_ones(int arr[] , int n){
    int count = 0 ;
    int max_ones = 0 ;

for(int i = 0 ; i  < n ; i++){
    if(arr[i] == 0){
        count=0;
    }
    else{
        count++;
    }
    max_ones = max_ones > count ? max_ones : count ;

}
cout << max_ones << endl;

}
int main()
{
    int arr[] = {1,1,0,0,1,1,1,0,1,1,1,1,0,0} ;
    int n = sizeof(arr)/4 ;

    
max_consecutivee_ones(arr , n);
return 0;
}