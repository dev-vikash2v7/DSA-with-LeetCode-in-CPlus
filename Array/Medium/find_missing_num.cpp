#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    int *temp = new int[n]{0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        temp[arr[i] - 1]++;
    }

    int i = 0;

    while (i < n)
    {
        if (temp[i] == 2)
            b = i+1;

        else if (temp[i] == 0)
            a = i + 1;
        i++;
    }
    //    for (int i = 0; i < n; i++)
    // {
    //     cout << temp[i] << endl;
    // }

    cout << endl;

    cout << b << " " << a << endl;
    return 0;
}