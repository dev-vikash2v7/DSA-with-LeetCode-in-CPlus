// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

#include <iostream>
#include <vector>

using namespace std;



   int removeDuplicates(vector<int>& nums) {
        
        int length = nums.size();

        if(length <= 2) return length;

        int actual_length_index = 2;

// If the current element nums[i] is different from the element two positions back (nums[index - 2]), it means it's a unique element.
        for(int i = 2 ; i<length ; i++){
                if(nums[i] != nums[actual_length_index-2])
                  // Replace the element at the current index with the unique element.
                   nums[actual_length_index++] = nums[i];
        } 

         for (const auto& element : nums) {
              cout << element << " ";
                }
    cout << endl;


        return actual_length_index;
    }




int main()
{
  
    vector<int> nums = {1,1,1,2,2,3};
    cout << removeDuplicates(nums) << endl;

    return 0;
}