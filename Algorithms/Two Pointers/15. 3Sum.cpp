#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<std::vector<int>> result;

        if(nums.size()<3) return result;

        sort(nums.begin() , nums.end() );

        for (int i = 0; i < nums.size() - 2; i++)
        {

            if( i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1 ;
            int k = nums.size()-1 ;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k] ;

                if(sum == 0){
                    result.push_back( {   nums[i] , nums[j] , nums[k]});

                    while (j < k && nums[j] == nums[j+1])
                            j++;

                    while (j < k && nums[k] == nums[k-1])
                            k--;

                    j++;
                    k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
    
        return result;
    }

int main()
{
   vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets with Sum 0:" << endl;

    for (const auto& triplet : result) {

        cout << "[";

        for (const int& num : triplet) {
            std::cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}