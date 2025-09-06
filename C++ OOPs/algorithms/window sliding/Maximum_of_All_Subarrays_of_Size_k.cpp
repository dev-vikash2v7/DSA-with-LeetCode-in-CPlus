#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxOfAllSubarrays(vector<int>& nums , int k) {

deque<int>indices ;
vector<int>result ;

for (int i = 0; i < nums.size(); i++) {

//check if window is full or not
if(!indices.empty() && indices.front() == i - k){
    indices.pop_front();
}

//check that front is always the largest indices value
while (!indices.empty() && nums[indices.back()] < nums[i]  )
{
   indices.pop_back();
}

//insert the indice
indices.push_back(i);


// store the front value of indices as it is largest but after the k window 

if ( i >= k-1)
result.push_back(nums[indices.front()]);


}

return result;


}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxOfAllSubarrays(arr, k);

    cout << "Maximum of all subarrays of size " << k << " are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}