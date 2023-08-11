#include <iostream>

using namespace std;
/*
time comp = O(n*n)
space = O(1)
*/
// void best_buy(int arr[], int n)
// {
//     int profit = 0;

//     for (int buy = 0; buy < n; buy++)
//     {

//         for (int sell = buy + 1; sell < n; sell++)
//         {

//             profit = profit > arr[sell] - arr[buy] ? profit : arr[sell] - arr[buy];
//         }
//     }
//     cout << profit << endl;
// }

/*
time comp = O(n)
space = O(n)
*/
// void best_buy(int arr[], int n)
// {
//     int *nextMx = new int[n];
//     int maxProfit = 0;

//     nextMx[n - 1] = arr[n - 1];

//     for (int i = n - 2; i >= 0; i--)
//     {
//         nextMx[i] = nextMx[i + 1] > arr[i] ? nextMx[i + 1] : arr[i];
//        maxProfit= maxProfit < (nextMx[i] -  arr[i])  ?(nextMx[i] -  arr[i])  : maxProfit;

//     }
//     cout << maxProfit << endl;
// }
/*
time comp = O(n)
space = O(1)
*/
void best_buy(int arr[], int n)
{
    int minbuy = arr[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        minbuy = minbuy > arr[i] ? arr[i] : minbuy;
        maxProfit = maxProfit < ( arr[i] - minbuy ) ? ( arr[i] - minbuy ) : maxProfit;
    }

    cout << maxProfit << endl;
}

int main()
{
    int arr[] = {3, 5, 1, 7, 4, 9, 3};
    int n = 7;
    best_buy(arr, n);

    return 0;
}