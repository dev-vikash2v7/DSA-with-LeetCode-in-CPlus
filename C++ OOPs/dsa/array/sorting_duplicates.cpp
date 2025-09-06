#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(vector<int>& nums) {

vector<int>res ; 

sort(nums.begin() , nums.end());

for (int i = 0; i < nums.size() - 1; i++) {

    if(nums[i] == nums[i+1] && (res.empty() || res.back() != nums[i])){
        res.push_back(nums[i]);
    }

}
    for(int num : res){
        cout << num << endl;
    }
}
int main()
{
    int n = 0;

vector<int> nums  = {3, 5, 1, 7, 4, 9, 3 , 1};
 func(nums);

    return 0;
}