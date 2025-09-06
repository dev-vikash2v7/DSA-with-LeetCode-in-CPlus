#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubarrayWithSum(const vector<int>& arr, int S) {
   
   int minLength = INT16_MAX ,  start = 0 , end = 1 ;
 int windowsum = arr[start];

   for ( end; end < arr.size(); end++)
   {

        windowsum += arr[end];

        while (windowsum > S)
        {
           windowsum -= arr[start];
           start++;
        }

        if(windowsum == S){
            minLength = min(minLength , end - start + 1);
        }
        
   }

   return minLength == INT16_MAX ? 0 : minLength;
   
}

int main() {
    vector<int> arr = {2, 1, 5 ,1} ;
    int S = 7;
    cout << "Minimum length of subarray with sum " << S << " is: " 
         << minSubarrayWithSum(arr, S) << endl; 

    return 0;
}
