#include <iostream>
#include <vector>
using namespace std;

// void reverse(std::vector<int>& arr, int start, int end) {
//     while (start < end) {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// Reverse method
//  void rotate(vector<int>&nums, int k) {
        
//         k =   k % nums.size();

//         reverse(nums , 0 , nums.size()-1);
//         reverse(nums , 0 , k -1);
//         reverse(nums , k ,  nums.size()-1);

//   for (const auto& num : nums) {
//         std::cout << num << " ";
//     }

//     }


 void right_rotate(vector<int>nums, int k) {
        
        k =   k % nums.size();

        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
                temp[(i+k) % nums.size()] = nums[i];
        }
        nums = temp ;

  for (const auto& num : nums) {
        std::cout << num << " ";
    }

    }


 void left_rotate(vector<int>nums, int k) {
        
        k =   k % nums.size();

        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
                temp[i] = nums[(i+k) % nums.size()];
        }
        nums = temp ;

  for (const auto& num : nums) {
        std::cout << num << " ";
    }

    }

int main()
{
   vector<int> nums = {1,2,3,4,5,6,7};
   int k = 3;

right_rotate(nums , k );

left_rotate(nums , k );

    return 0;
}