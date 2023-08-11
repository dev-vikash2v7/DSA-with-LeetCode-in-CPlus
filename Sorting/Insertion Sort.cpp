#include <iostream>

using namespace std;

int *Insertion_sort(int *arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int cur = arr[i];
        while (cur < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            arr[j + 1] = cur;
        }
    }
    return arr;
}
int main()
{
    int size = 6; // 0    1   2   3   4    5
    int *arr = new int[size]{12, 54, 65, 7, 23, 9};

    arr = Insertion_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}