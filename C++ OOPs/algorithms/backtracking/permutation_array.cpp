#include <iostream>
#include <vector>
using namespace std;


 vector<vector<int>> result ;

 vector<vector<int>>permute(vector<int>& nums , int start ){

    if(start == nums.size()){
         result.push_back(nums);
         return result;
    }

    for(int i = start ; i < nums.size() ;i++){

        swap(nums[i] , nums[start]);
        permute(nums , start + 1);
        swap(nums[i] , nums[start]); //backtrack

    }

    return result;


 }



int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums , 0);

    cout << "Permutations of the array: " << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) cout << num << " ";
        cout << endl;
    }

    return 0;
}
