#include <iostream>
#include <limits>

using namespace std;


/*
Method 1 There can be two cases for the maximum sum:  

Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.
Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. Let us see how. Wrapping of contributing elements implies non-wrapping of non-contributing elements, so find out the sum of non-contributing elements and subtract this sum from the total sum. To find out the sum of non-contributions, invert the sign of each element and then run Kadane’s algorithm. 
Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays. Finally, we compare the sum obtained in both cases and return the maximum of the two sums.
*/
int Kadans(int arr[], int n)
{

    int max_sum = -2147483647;

    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        max_sum = max(max_sum, curr_sum);

        if (curr_sum < 0)
            curr_sum = 0;
    }

    return max_sum;
}

int circularSubarraySum(int arr[], int n)
{
    // case 1
    int max_kadans = Kadans(arr, n);

    if (max_kadans < 0)
        return max_kadans;

    int max_wrap = 0;
    for (int i = 0; i < n; i++)
    {
        max_wrap += arr[i];
        arr[i] = -arr[i];
    }
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    int min_kadans = Kadans(arr, n);
    max_wrap += min_kadans;

    cout <<max(max_wrap, max_kadans)<< endl;

    return max(max_wrap, max_kadans);
}

int main()
{
    const int n = 8;
    // cin >> n ;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    circularSubarraySum(arr, n);
    return 0;
}




/*
Approach 2:
 In this method, modify Kadane’s algorithm to find a minimum contiguous subarray sum and the maximum contiguous subarray sum, then check for the maximum
 value between the max_value and the value left after subtracting min_value from the total sum.


 Algorithm 

We will calculate the total sum of the given array.
We will declare the variable curr_max, max_so_far, curr_min, min_so_far as the first value of the array.
Now we will use Kadane’s Algorithm to find the maximum subarray sum and minimum subarray sum.
Check for all the values in the array:- 
If min_so_far is equaled to sum, i.e. all values are negative, then we return max_so_far.
Else, we will calculate the maximum value of max_so_far and (sum – min_so_far) and return it.
*/
int maxCircularSum2(int a[], int n)
{
    // Corner Case
    if (n == 1)
        return a[0];
 
    // Initialize sum variable which store total sum of the array.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
 
    // Initialize every variable with first value of array.
    int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {

      // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);
 
        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
 
    if (min_so_far == sum)
        return max_so_far;
 
    // returning the maximum value
    return max(max_so_far, sum - min_so_far);
}
 