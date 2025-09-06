#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Process each element in the array
    for (int num : nums) {
        minHeap.push(num);
        
        // If the heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // The root of the min-heap is the k-th largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "-th largest element is " << findKthLargest(nums, k) << endl;

    return 0;
}
