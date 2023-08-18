#include <iostream>

using namespace std;

int find_pivoted(int arr[], int low, int high)
{
    if (low >= high)
        return -1;

    int mid = (low + high) / 2;

    // cout << low << " " << high << " " << mid << endl;

    if (low < mid && arr[mid] < arr[mid - 1])
        return mid - 1;

    if (high > mid && arr[mid] > arr[mid + 1])
        return mid;

    if (arr[mid] <= arr[low])
        return find_pivoted(arr, low, mid - 1);

    return find_pivoted(arr, mid + 1, high);
}





int BinarySearch(int arr[], int low, int high, int key)
{
    cout << low << " " << high << endl;

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        return BinarySearch(arr, mid + 1, high , key);

    return BinarySearch(arr, 0, mid-1 , key);

}




int Search_PivotedArray(int arr[], int n, int key)
{
    int pivot_ind = find_pivoted(arr, 0, n - 1);
cout << "pivot " << pivot_ind << endl;

    if (arr[pivot_ind] == key)
        return pivot_ind;

    if (pivot_ind == -1)
        return BinarySearch(arr , 0 , n-1 , key);

    else if (arr[pivot_ind] < key)
        return BinarySearch(arr, 0, pivot_ind, key);

    else
        return BinarySearch(arr, pivot_ind + 1, n - 1, key);
}

int main()
{
    int n , key;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    cin >> key ;

    int result = Search_PivotedArray(arr, n, key);
    cout << "Result : " << result << endl;
    return 0;
}