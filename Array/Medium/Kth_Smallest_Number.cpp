#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

// Method 1 (Map STL)
// A map-based STL approach is although very much similar to the quickselect and counting sort algorithm  but much easier to
// implement. We can use an ordered map and map each element with its frequency.
// And as we know that an ordered map would store the data in a sorted manner, we keep on adding the frequency of each element till it does not become greater
// than or equal to k so that we reach the k’th element from the start i.e. the k’th smallest element.

// int kthSmallest(int arr[], int n, int k)
// {
//     map<int, int> m;

//     for (int i = 0; i < n; i++)
//         m[arr[i]]++; // mapping every element with it's    // frequency
//     int i = 1;
//     for (auto it = m.begin() ; it != m.end(); it++){
//         cout << it->first << " " << it->second << endl;
//         if (i == k )    return it->first;
//         i++;
//     }
//     auto it = m.begin();
//     advance(it, k-1);
//     return it->first;

// }

// approch 2  - Max heap using STL
//  We can implement max and min heap using a priority queue.
//  To find the kth minimum element in an array we will max heapify the array until the size of the heap becomes k.
//  After that for each entry we will pop the top element from the heap/Priority Queue.

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    int i = 0;

    while (!pq.empty())
    {
        if (i == n - k)
            return pq.top();

       pq.pop();
       i++;
    }
    cout <<"end" <<  endl ;
    return pq.top();
}

// int kthSmallest(int arr[], int n, int k)
// {
//     set<int> s(arr, arr + n);
//     set<int>::iterator itr = s.begin(); // s.begin() returns a pointer to first
//                                         // element in the set
//     advance(itr, k - 1);                // itr points to kth element in set

//     return *itr ;
// }

int main()
{
    int n, k =5;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << kthSmallest(arr, n, k) << endl;

    return 0;
}