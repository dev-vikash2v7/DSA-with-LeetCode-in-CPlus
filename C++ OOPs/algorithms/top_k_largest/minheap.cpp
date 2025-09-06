#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<int> findTopKLargest(const vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);

        // Maintain heap size of k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract elements from the heap to get the k largest elements
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Optional: To get the result in descending order
    sort(result.begin(), result.end(), greater<int>());

    return result;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 3;
    vector<int> result = findTopKLargest(nums, k);

    cout << "Top " << k << " largest elements are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
