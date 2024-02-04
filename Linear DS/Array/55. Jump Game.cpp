#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
        
        int maxReach = 0 ;
        int last_index = nums.size() - 1 ;

         for (int i = 0; i < nums.size(); i++) {

               // Check if the current index is beyond the maximum reachable index
                if (i > maxReach) {
                    return false;
                }
              int maxJump =  nums[i];

                
              maxReach = max(maxReach , i + maxJump );

              if(maxReach >=last_index){
                return true;
              }

           }
    }


int main()
{
    

vector<int> nums  = {2,2,1,1,4};
cout <<  canJump(nums)<<endl;

    return 0;
}