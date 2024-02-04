#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
        
        int last_index = nums.size() - 1 ;
        int  minCount = 0;
        int nextMaxReach = 0;     // The farthest position you can reach in the next jump
        int currentMaxReach = 0 ;
        

    for (int i = 0; i < last_index; ++i) {

cout << "i = "<<  i << endl;
cout << "mincount = "<<  minCount << endl;
cout << "currentMaxReach = "<<  currentMaxReach << endl;
cout << "nextMaxReach = "<<  nextMaxReach << endl;
cout<< endl;

        // Update the nextMaxReach based on the current jump
        nextMaxReach = max(nextMaxReach, i + nums[i]);

        // If you reach the current maximum reach, make a jump
        if (i == currentMaxReach) {
            minCount++;
            currentMaxReach = nextMaxReach;

            // If the last element is reachable, break the loop

            if (currentMaxReach >= last_index) {
                break;
            }
        }
    }
           return minCount;
}


int main()
{
    

vector<int> nums  = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
cout <<  jump(nums)<<endl;

    return 0;
}