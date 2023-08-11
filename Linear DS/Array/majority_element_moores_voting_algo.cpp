#include <bits/stdc++.h>

using namespace std;

void func(int arr[], int n)
{
    int freq = 0;
    int major_elem = -1;

    for (int curr = 0; curr < n; curr++)
    {
        if (freq == 0)
        {
            major_elem = arr[curr];
            freq = 1;
        }
        else
        {
            if (major_elem == arr[curr])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
    }

    freq = 0;
    for (int curr = 0; curr < n; curr++)
    {
        if (arr[curr] == major_elem)
        {
            freq++;
        }
    }

    if (freq < n / 2)
    {
        cout << "no majoritiy element\n";
    }
    else
    {
        cout << major_elem << endl;
        cout << "freq " << freq << endl;
    }
}

int main()
{
    int arr[] = {5, 5, 6, 1, 5, 6, 4, 1};
    int n = sizeof(arr) / 4;
    func(arr, n);

    return 0;
}

/*
curr , major_elem , freq ,
         5           ,  1
5         5            2
6         5             1
5          5             2
 1         5              1
 6         6                0




*/