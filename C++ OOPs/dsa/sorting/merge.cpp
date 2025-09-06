#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums , int mid , int l , int r){

   

int i = 0 , j = 0 , k = l;

int n1 = mid - l + 1;
int n2 = r - mid ;

vector<int> left , right;  

for(int i = 0 ; i < n1 ; i++) left.push_back(nums[l + i]);
for(int i = 0 ; i < n2 ; i++) right.push_back(nums[ mid + i + 1]);

while (i<n1 && j<n2)
{
    if(left[i] < right[j]){
        nums[k] = left[i];
        i++;
    }
    else{
        nums[k] = right[j];
        j++;
    }
    k++;
}

while (i<n1)
{
      nums[k] = left[i];
        i++;
        k++;

}

while (j<n2)
{
        nums[k] = right[j];
        j++;
        k++;
}




}


void mergesort(vector<int>& nums ,  int l , int r) {

if(l >= r){
    return  ;
}
int mid = l + (r-l) / 2;

// cout << mid <<endl;

 mergesort(nums , l , mid );
 mergesort(nums ,  mid + 1, r);

  merge(nums  , mid , l , r);

}

void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}







int main()
{

vector<int> nums  = {3, 5, 1, 7};
 mergesort(nums ,  0 , nums.size()-1);

   cout << "\nSorted vector is \n";
    printVector(nums);
    return 0;
}