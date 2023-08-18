#include <iostream>
#include <vector>

using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &arr, int n)
{
    long long int prod = 1;

    vector<long long int> result(n, 0);

    if (n == 1)
        return result;

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (c == 1)
                return result;
            c++;
        }
        else
            prod *= arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            result[i] = prod;
        }
        else
        {
            if (c == 1)
            {
                result[i] = 0;
            }
            else
            {
                result[i] = (prod / arr[i]);
            }
        }
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n;

    vector<long long int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long int> result = productExceptSelf(arr, n);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    cout << endl;
    return 0;
}