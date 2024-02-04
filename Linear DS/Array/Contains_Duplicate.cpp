/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    vector<int> orig;

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int>::iterator itr = find(orig.begin(), orig.end(), nums[i]);
        if (itr == end(orig))
        {
            orig.push_back(nums[i]);
        }
        else  return true;
    }

    return false;
}
int main()
{
    vector<int> nums{-2, 1, -3, 4, -19, 2, 10, -5, 49};
    cout << containsDuplicate(nums);
    return 0;
}