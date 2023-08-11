#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void permutation(vector<int> &arr, int n, int idx)
{
    if (idx = n)
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(arr[i], arr[idx]);
        permutation(arr, n, idx + 1);
        swap(arr[i], arr[idx]);
    }
    return;
}

int main()
{
    int n = 3;
    vector<int> arr{1, 2, 3}; // 123 132 213 231 321 312

    permutation(arr, 3, 0);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}