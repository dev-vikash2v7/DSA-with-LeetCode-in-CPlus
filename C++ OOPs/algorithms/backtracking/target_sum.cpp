#include <iostream>
#include <vector>
using namespace std;


void calculateWays(vector<int>& nums, int target , int & count , int index, int sum){

    if(index == nums.size()){
        if(target == sum){
            count++;
        }
            return;
    }

    calculateWays(nums , target , count , index+1 , sum + nums[index]);
    calculateWays(nums , target , count , index+1 , sum - nums[index]);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0;
    calculateWays(nums , target , count , 0  , 0 );
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "Number of ways to reach target sum: " << findTargetSumWays(nums, target) << endl;

    return 0;
}
