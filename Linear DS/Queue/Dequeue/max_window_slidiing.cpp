#include <iostream>
#include <QUEUE>

using namespace std;

vector<int> res;

void show(vector<int> res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

/*
method 1
brute for approch - O( n * k)

1.Outer loop -> take all subarrays of size k - O(n)
2. inner loop -> get the maximam of the current subarray - O(k)

O(n * k)

*/

// void max_window(int arr[], int n, int k)
// {
//     for (int i = 0; i <= n - k; i++)
//     {
//         int max = arr[i];
//         for (int j = i + 1; j < i + k; j++)
//         {
//             if (arr[j] > max)
//             {
//                 max = arr[j];
//             }
//         }
//         res.push_back(max);
//     }
// }

int max(queue<int> q)
{
    int m = -99999;

    while (!q.empty())
    {
        if (q.front() > m)
        {
            m = q.front();
        }
        q.pop();
    }

    return m;
}
/*
method 2 - priority queue

1.creat self balancing binary search tree of first k elements - O(k logk)
2.run loop for i=0 to n-k                                      - O(n-k+1)
3.  print max element of BST                                   - O(log k)
4.  search for arr[i] and delete it from BST                   - O(log k)
5.  insert arr[i+k] into the BST                                -O(log k)

O(k log k + (n-k+1)*log k)

*/

// void max_window(int arr[], int n, int k)
// {
//     queue<int> q;
//     int i = 0;
//     for (; i < k; i++)
//     {
//         q.push(arr[i]);
//     }
//     res.push_back(max(q));
//     q.pop();

//     for (; i < n; i++)
//     {
//         q.push(arr[i]);
//         res.push_back(max(q));
//         q.pop();
//     }
// }

/*
Dequeu approch - O(n)

1.create a dequeu , DQ (of capacity k) it stores only usefull elements of current window of k elements

# an element is usefull if : it is in current window 
                             it is greater than all other elements on left isde of it in current window

 */ 
void max_window(int arr[], int n, int k)
{
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {

//remove front  if window is closed
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

// maintain order in decreasin order
        while (!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

//when first window is complete
        if (i >= k - 1)
            res.push_back(arr[dq.front()]);

        for (auto i : dq)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int arr[] = {4, 1, 3, 5, 1, 2, 3, 2, 1, 1, 5};
    int k = 3;
    max_window(arr, 11, k);
    show(res);

    return 0;
}