// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most thrice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

#include <iostream>
#include <vector>

using namespace std;



   int removeDuplicates(vector<int>& nums) {
        
        int length = nums.size();

        if(length <= 3) return length;

       int unique_start_index = 3;

       for(int i = 3 ; i < length ; i++){
        if(nums[i] != nums[unique_start_index]){
            nums[unique_start_index] = nums[i];
            unique_start_index++;
        }
       }


         for (int i = 0 ; i < unique_start_index ; i++) {
              cout << nums[i] << " ";
                }
    cout << endl;

       return unique_start_index;
    }




int main()
{
  
    vector<int> nums = {1,1,1,1,2,2,2,3,3,3,3,3,4,4,5,5,5};
    cout << removeDuplicates(nums) << endl;

    return 0;
}