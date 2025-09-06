#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTopKLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> result(nums.begin(), nums.begin() + k);
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
