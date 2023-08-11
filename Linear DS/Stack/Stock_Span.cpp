#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void show(vector<int> res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

// vector<int> stockSpan(int arr[], int n)
// {
//     vector<int> res;

//     for (int i = 0; i < n; i++)
//     {
//         int day = 1;

//         int prev = i - 1;

//         while (prev >= 0 && arr[i] > arr[prev])
//         {
//             day++;
//             prev--;
//         }
//         res.push_back(day);
//     }
//     return res;
// };
vector<int> stockSpan(vector<int> prices, int n)
{
    stack<pair<int, int>> s;
    vector<int> res;

    for (auto price : prices)
    {
        int days = 1;

        while (!s.empty() && price >= s.top().first)
        {
            days += s.top().second;
            s.pop();
        }

        s.push({price, days});
        res.push_back(days);
    }
    return res;
};

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(prices, 7);
    show(res);

    return 0;
}