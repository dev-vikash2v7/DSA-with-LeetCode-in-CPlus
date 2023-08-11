#include <iostream>

using namespace std;

/*
method - two pointer technique

1.sort the array
2.travere the array and fix the first element of the triplet
  the problem reproduces to find if there exist two elements having sum equal to x-array[i]
*/
bool threeSum(int arr[], int n, int target)
{

    for (int i = 0; i < n; i++)
    {
        int a = arr[i];

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = a + arr[left] + arr[right];
            if (sum == target)
            {
                cout << a << " " << arr[left] << " " << arr[right] << endl;
                return true;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

    }
    return false ;
}
int main()
{
    int arr[] = {1, 3, 6, 7, 9, 12};

    if (threeSum(arr, 6, 24))
    {
    }
    else
    {
    }
    return 0;
}