#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// by commulative sum method
int maxSubArray_Brute(vector<int> &nums)
{
    cout << "In Brute Force Algorithm\n";
    int n = nums.size();
    int steps = 0;

    int max_sum = INT_MIN;

    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            curr_sum += nums[j];
            max_sum = max(max_sum, curr_sum);
            steps++;
        }
        curr_sum = 0;
    }
    cout << "max sum " << max_sum << endl
         << "find in " << steps << " of steps\n\n";
    return 0;
}
// by commulative sum method
int maxSubArray_Commulative(vector<int> &nums)
{
    cout << "Commulative Sum method\n";
    int n = nums.size();
    int subArr_sum[n];
    subArr_sum[0] = nums[0];

    int max_sum = subArr_sum[0];
    int steps = 0;

    for (int i = 1; i < n; i++)
    {
        steps++;
        subArr_sum[i] = subArr_sum[i - 1] + nums[i];
        max_sum = max(max_sum, subArr_sum[i]);
    }

    int curr_sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            steps++;
            curr_sum = subArr_sum[j] - subArr_sum[i];
            max_sum = max(max_sum, curr_sum);
        }
    }
    cout << "max sum " << max_sum << endl
         << "find in " << steps << " of steps\n";
    return 0;
}
// by Kadans Algorithm
int maxSubArray_Kadans(vector<int> &nums)
{
    cout << "By Kadans Algorithm\n";
    int steps = 0;
    int n = nums.size();

    int max_sum = INT_MIN;

    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];

        max_sum = max(max_sum, curr_sum);

        if (curr_sum < 0)
            curr_sum = 0;

        steps++;
    }

    cout << max_sum << endl
         << "find in " << steps << " steps\n\n";
    return 0;
}

int main()
{
    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};// 6
    vector<int> nums{-1, 4, 7, 2}; // 13 // {-1 , 3 , 10 , 12} {3 - (-1) , 11 - (-1), -1 - +12   } {  10 - 3 , 12 - 3}

    // maxSubArray_Brute(nums);
    // maxSubArray_Commulative(nums);
    maxSubArray_Kadans(nums);

    // for (int x : nums)
    //     cout << x << " ";

    return 0;
}