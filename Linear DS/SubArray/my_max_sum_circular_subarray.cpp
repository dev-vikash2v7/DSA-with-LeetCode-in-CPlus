#include <iostream>
#include <limits.h>

using namespace std;

int Kadans_Sum(int arr[], int n)
{
    int temp_sum = 0;
    int max_straight_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        temp_sum += arr[i];

        if (temp_sum < 0)
            temp_sum = 0;
        max_straight_sum = max(temp_sum, max_straight_sum);
    }

    return max_straight_sum;
};

// int maxSum(int arr[], int n)
// {
//     int max_straight_sum = Kadans_Sum(arr, n);

//     // case 1
//     if (max_straight_sum < 0)
//         return max_straight_sum;

//     int total_arr_sum = 0;

//     for (int i = 0; i < n; i++)
//     {
//         total_arr_sum += arr[i];
//         arr[i] = -arr[i];
//     }

//     int min_straight_sum = Kadans_Sum(arr, n);

//     int max_wrap_sum = total_arr_sum + min_straight_sum;

//     cout << max_straight_sum << endl
//          << min_straight_sum << endl
//          << max_wrap_sum << endl
//          << total_arr_sum << endl;

//     return max(max_straight_sum, max_wrap_sum);
// }

// approch 2
int maxSum2(int arr[], int n)
{
    int max_straight_sum = INT_MIN;
    int temp_max_sum = 0;

    int total_arr_sum = 0;

    int min_straight_sum = INT_MAX;
    int temp_min_sum = 0;

    for (int i = 0; i < n; i++)
    {
        temp_max_sum += arr[i];
        temp_min_sum += arr[i];

        total_arr_sum += arr[i];

        if (temp_max_sum < 0)
            temp_max_sum = 0;
        max_straight_sum = max(temp_max_sum, max_straight_sum);

        if (temp_min_sum > 0)
            temp_min_sum = 0;
        min_straight_sum = min(temp_min_sum, min_straight_sum);
    }

    if (max_straight_sum < 0)
        return max_straight_sum;

    int max_wrap_sum = total_arr_sum - min_straight_sum;

    cout << max_straight_sum << endl
         << min_straight_sum << endl
         << max_wrap_sum << endl
         << total_arr_sum << endl;

    return max(max_straight_sum, max_wrap_sum);
}
int main()
{
    int nums[] = {5, -3, -2, 6, 7, -1};

    int n = 6;

    int max_sum = maxSum2(nums, n);

    cout << "max sum : " << max_sum << endl;

    return 0;
}

// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2: