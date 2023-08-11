#include <bits/stdc++.h>

using namespace std;

void func(int arr[], int n , int k  )
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == k)
        {
            cout << mid << endl;
            return;
        }
        // if left part sorted
        else if (arr[l] < arr[mid])
        {
            if (k >= arr[l] && k < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // for right part
        else
        {
              if (k > arr[mid] && k <= arr[h])
            { 
                l = mid + 1 ; 
            }
            else
            {
                 h = mid - 1 ;
            }

        }
    }
    cout << -1 << endl;
}

int main()
{
    int arr[] = {8, 9, 10,    11, 1, 2 , 3, 4 , 5 ,6 , 7};
    int n = sizeof(arr) / 4;
    int k = 0;


while (k++ <= 11)
{
  cout << k << " " ; func(arr, n ,k ) ;cout<<endl;
    /* code */
}


    return 0;
}