#include <iostream>

using namespace std;

int find_pivot(int arr[], int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (high > mid && arr[mid] > arr[mid + 1])
        return mid;

    if (low < mid && arr[mid] < arr[mid - 1])
        return mid - 1;

    if (arr[low] >= arr[mid])
        return find_pivot(arr, low, mid - 1);

    return find_pivot(arr, mid + 1, high);
};

int BinarySearch(int arr[], int l, int h, int key)
{
    if(l > h )return -1;
    int mid = (h + l) / 2;

    if (key == arr[mid])
        return mid;

    else if (arr[mid] < key)
    {
        return BinarySearch(arr, l + 1, h, key);
    }
    else
    {
      return  BinarySearch(arr, l, h - 1, key);
    }
}

int Search_Num(int A[], int n, int key)
{
    int pivot_ind = find_pivot(A, 0, n - 1);
    cout << "pivoted point " << pivot_ind << endl;

    // if pivot point not find then array is not rotated
    if (pivot_ind == -1)
        return BinarySearch(A, 0, n - 1, key);

    // pivot point find
    else if (key == A[pivot_ind])
        return pivot_ind;

    // if element is left on pivot index
    else if (A[0] <= key)
        return BinarySearch(A, 0, pivot_ind - 1, key);

    // if elemetn is on right index
    return BinarySearch(A, pivot_ind + 1, n - 1, key);
}

int main()
{
    int n, key;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    int result = Search_Num(arr, n, key);

    cout << "index : " << result << endl;
    return 0;
}

/*


int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;

    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);

        return search(arr, mid + 1, h, key);
    }

    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);

    return search(arr, l, mid - 1, key);
}


*/