#include <iostream>
#include <limits.h>

using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);

    return i + 1;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    // if (l < r)
    // {
    //     int pivot_ind = partition(arr, l, r);

    //     cout << pivot_ind << endl;

    //     if (pivot_ind == k-1){
    //     cout << pivot_ind << endl;
    //         return ;
    //     }

    //     kthSmallest(arr, l, pivot_ind - 1, k);
    //     kthSmallest(arr, pivot_ind + 1, r, k);
    // }
    // If k is smaller than number of elements in array


        if (k > 0 && k <= r - l + 1)
        {
            // Partition the array around last element and get
            // position of pivot element in sorted array
            int pos = partition(arr, l, r);

            // If position is same as k
            if (pos - l == k - 1)
                return arr[pos];
                
            if (pos - l > k - 1) // If position is more, recur for left subarray
                return kthSmallest(arr, l, pos - 1, k);

            // Else recur for right subarray
            return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
        }

        // If k is more than number of elements in array
        return INT_MAX;
}

int main()
{
    int n, k;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    k = 5;
    cout <<"kth smallest element : " << kthSmallest(arr, 0, n - 1, k) << endl;

    return 0;
}