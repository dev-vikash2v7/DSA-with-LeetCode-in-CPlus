#include <iostream>
#include <vector>
using namespace std;


int majorityElement(vector<int>& nums) {
        
        int maj_elm = nums[0];
        int current_count = 1;

       for(int i = 1 ; i < nums.size() ; i++){

        if(current_count)
            maj_elm = nums[i];

        else if( nums[i] == maj_elm)
            current_count++;

        else 
            current_count--;
       }
       return maj_elm;
    }
int main()
{
     vector<int> nums = {1,1,1,1,2,2,2,3,3,3,3,3,4,4,5,5,5};
    cout << majorityElement(nums) << endl;

    return 0;
}