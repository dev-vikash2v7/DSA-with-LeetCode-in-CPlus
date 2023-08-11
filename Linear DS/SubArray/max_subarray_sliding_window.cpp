#include <bits/stdc++.h>

using namespace std;
/*
method 1
1. outer loop - take all subarrays of size k
2. inner loop - get max of current subarray
*/
void show(int arr[])
{
    int n = sizeof(arr) / 4;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void brute_max(int arr[], int n, int k)
{

    int max;
    int result[n - k];
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }
        cout << max << " ";
        result[i] = max;
    }

    // show(result );
}

/*
method 2

In the above-mentioned methods, one of them was using AVL tree. This approach is very similar to that approach.
The difference is that instead of using the AVL tree, Max-Heap will be used in this approach.
The elements of the current window will be stored in the Max-Heap and the maximum element or the root will be printed in each iteration.

1. create self balancing binary tree of first k elements
2. run a loop for i =0 to n-k
        * print max element of BST
        * search for arr[i] and delete it from the BST
        * insert arr[i+k] into the BST
*/
void BST_max(int arr[], int n, int k)
{

    int max;
    int result[n - k];
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }
        result[i] = max;
    }
}

/*
method 3

1.create a deque , Qi (of capacity k) . it stores only useful elements of current window of k elements
2. an element is useful if :
    * it is in current window
    * it is greater than all other elements on left side of it in current window
    *

whenever new window
1. output - arr[dq.front()]
2/ remove index not of the current window


Create a Deque, Qi of capacity K, that stores only useful elements of current window of K elements.
 An element is useful if it is in current window and is greater than all other elements on right side of it in current window.
  Process all array elements one by one and maintain Qi to contain useful elements of current window and these useful elements are maintained in sorted order.
 The element at front of the Qi is the largest and element at rear/back of Qi is the smallest of current window.


 Follow the given steps to solve the problem:

Create a deque to store K elements.
Run a loop and insert the first K elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Now, run a loop from K to the end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.
*/
void deque_max(int arr[], int n, int k)
{

    int max;
    vector<int> result;

    deque<int> dq;

    for (int i = 0; i < n; i++)
    {

        if (i >= k)
        {
            result.push_back(arr[dq.front()]);
        }

        // Remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k)
            // Remove from front of queue
            dq.pop_front();

        // Remove all elements smaller than the currently being added element (remove useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        // Add current element at the rear of Qi
        dq.push_back(i);
    }
    result.push_back(arr[dq.front()]);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = sizeof(arr) / 4;
    int k = 3;
    // brute_max(arr,n , k);
    // BST_max(arr,n , k);
    deque_max(arr, n, k);

    return 0;
}

/*
given -> an array and an integer k
find max for each and every contigunous subarray of size k

8  ,  5 , 10 , 7 , 9 , 4 , 15 , 12, 90 , 13
10 10 10 9 15 15 90 90
*/