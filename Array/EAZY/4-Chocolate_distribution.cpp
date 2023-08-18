// Given an array of n integers where each value represents the number of chocolates in a packet.
// Each packet can have a variable number of chocolates.
//  There are m students, the task is to distribute chocolate packets such that:

// Each student gets one packet.
// The difference between the number of chocolates in the packet
// with maximum chocolates and packet with minimum chocolates given to the students is minimum.

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{

    const int n = 8;
    int m = 5;
    int min_diff = INT_MAX;

    int arr[n] = {3, 4, 1, 9, 56, 7, 9, 12};
    sort(arr, arr + n);
    for (int i = 0; i <= n - m; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        min_diff = min(min_diff, diff);
    }
    cout << min_diff << endl;
    return 0;
}
