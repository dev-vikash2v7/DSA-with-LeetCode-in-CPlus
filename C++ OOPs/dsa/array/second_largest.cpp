#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& nums) {

if(nums.size() < 2) {
    return -1 ;
};

int first = -999;
int second = -999;

for (int i = 0; i < nums.size(); i++) {

    if(nums[i] > first){
        second = first ;
        first = nums[i];
    }
}

return second;
}


int main()
{
   
vector<int> nums  = {3, 5, 1, 7, 4, 9, 3};
cout <<  func(nums);

    return 0;
}