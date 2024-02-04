#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

const int n = 4;


int maxProfit(int prices[n])
{
    int min_buy = prices[0], max_profit = 0;

    for (int i = 1; i < n ; i++)
    {
        min_buy = min(min_buy , prices[i]); 
        max_profit = max( max_profit , prices[i] - min_buy ); 
    }

    return max_profit;
}

int main()
{
    // cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProfit(arr) << endl;
    return 0;
}