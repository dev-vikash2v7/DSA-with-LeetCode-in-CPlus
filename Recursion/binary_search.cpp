#include <iostream>
#include <algorithm>

using namespace std;

int low, high, mid;

int bin_search(int low  , int high, int arr[], int data)
{
    cout << low << " " << high << endl;

    if (low > high)
        return -1;

    mid = (low + high) / 2; // 3

    if (arr[mid] == data)
        return mid;

    else if (data < arr[mid])
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }

    return bin_search(low ,  high  , arr, data);
}
int main()
{
    int n = 5;
    int arr[5] = {1, 5, 37, 1, 9}; // {1 , 1 , 5 , 9 , 37}

    int data = 1;
    low = 0;
    high = n - 1;

    sort(arr, arr + n);
    cout <<"intex at : " <<  bin_search(low , high, arr, data) << endl;
    return 0;
}
