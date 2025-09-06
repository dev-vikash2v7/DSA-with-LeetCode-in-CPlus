#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& nums , int k ) {

int maxsum = 0 , windowsum = 0 ;


for(int i = 0  ; i < k ; i++){
    windowsum += nums[i];
}

maxsum = windowsum;


for(int i = k  ; i < nums.size() ; i++){
     windowsum = windowsum - nums[i-k] + nums[i];

    if(windowsum > maxsum){
        maxsum = windowsum;
    }
}


return maxsum;

}
int main()
{
   
   int k = 3;
vector<int> nums  = {3, 5, 1, 7, 4, 9, 3};
cout <<  func(nums , k);

    return 0;
}