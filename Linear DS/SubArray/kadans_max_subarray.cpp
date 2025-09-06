// #include <iostream>

// using namespace std;

// void maxSubarray(int arr[] , int n){
//     int maxSum = -9999 ;
//     int current = 0 ;

//     for (int i = 0  ; i < n ; i++){
//         current += arr[i];
//         maxSum = current > maxSum ? current : maxSum ;
//         if(current < 0) current = 0 ;
//     }
//     cout << maxSum << endl;
// }

// int main()
// {
//     // int arr[]  = {-5, 4, 6 , -3, 4,1};
//     int arr[]  = {-5, -4, -2 , -6 ,-1};
//      int n = 5;
//      maxSubarray(arr , n);
// return 0;
// }


#include <iostream>

using namespace std;


int KadansMaxSubarray(int n , int arr[]){

    int maxsum_ = -9999;

    int current = 0 ;

    for(int i = 0 ; i < n ; i++){

        current += arr[i] ; 

        maxsum_  = current > maxsum_ ? current : maxsum_ ; 

       current =  current < 0 ? 0 : current ;

    }

    return maxsum_ ; 
}

int main(){
    int n = 5 ; 

    int arr[5] = {3 , 4, -5, -10 , 18} ;

    int res =  KadansMaxSubarray(n , arr);

    cout << "Max" << res << endl; 
}