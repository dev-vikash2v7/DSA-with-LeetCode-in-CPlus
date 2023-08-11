#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int subarray_sum = 0;

        for (int j = i; j < n; j++)
        {
            subarray_sum += arr[j];

            if (subarray_sum == s)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                cout << i + 1 << " " << j + 1 << endl;
                return result;
            }
            else if (subarray_sum > s)
            {
                break;
            }
        }
    }

    result.push_back(-1);
    return result;
}
int main()
{

    int N = 10, S = 15, A[] = {1,2,3,4,5,6,7,8,9,10};
    subarraySum(A, N, S);
    return 0;
}