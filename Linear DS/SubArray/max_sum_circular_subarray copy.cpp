#include <iostream>
#include <limits.h>

using namespace std;

int Kadans_Sum(int arr[], int n)
{
    int sum = 0;
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // 1  -1  3 1

        max_sum = max(max_sum, sum); // 1  1  3 3

        if (sum < 0)
            sum = 0;
    }
    return max_sum;
};

int maxSum(int arr[], int n)
{
    int max_straight_sum = Kadans_Sum(arr, n);

    // cout << max_subarray_sum << endl;

    if (max_straight_sum <= 0)
        return max_straight_sum; // if all numbers are negative we not required to check

    int total_sum = 0;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        arr[i] = -arr[i];
    }

    int min_straight_sum = Kadans_Sum(arr, n);
    // cout << "total : " << total_sum << " " << min_straight_sum << endl;

    int wrap_sum = total_sum + min_straight_sum;

    return max(wrap_sum, max_straight_sum);
}

// approch 2
int maxSum2(int arr[], int n)
{
    int max_straight_sum = INT_MIN; // 5 5 5 6 9
    int min_straight_sum = INT_MAX; // 0 5 -3

    int arr_sum = 0; // 9

    int temp_max_sum = 0; // 5 2 0 6 5 9
    int temp_min_sum = 0; // 0 5 0 -3

    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];

        temp_max_sum += arr[i];

        max_straight_sum = max(temp_max_sum, max_straight_sum);
        if (temp_max_sum < 0)
            temp_max_sum = 0;

        temp_min_sum += arr[i];
        min_straight_sum = min(temp_min_sum, min_straight_sum);

        if (temp_min_sum > 0)
            temp_min_sum = 0;
    }

    cout << max_straight_sum << endl
         << min_straight_sum << endl
         << arr_sum << endl;

    if(arr_sum == min_straight_sum) return max_straight_sum ;

    int max_wrap_sum = arr_sum - min_straight_sum ;
    cout << max_wrap_sum <<endl;

    max_straight_sum = max(max_straight_sum , max_wrap_sum) ;

    return max_straight_sum;
}
int main()
{
    int nums[] = {5, -3, -2, 6, 7, -1};

    int n = 6;

    int max_sum = maxSum(nums, n);
    // int max_sum = maxSum2(nums, n);

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