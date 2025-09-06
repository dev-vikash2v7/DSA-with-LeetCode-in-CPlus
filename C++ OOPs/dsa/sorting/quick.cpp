#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int findPivot(vector<int>& nums , int l ,int r){

    int pivot =  nums[r];

    int pivot_index = l - 1 ;

    for(int i = l  ; i < r ; i++){

            if(pivot > nums[i]){
                pivot_index++;
                swap(nums[i] , nums[pivot_index]);
            }
    }

    swap(nums[pivot_index + 1] , nums[r]);
       
    return pivot_index + 1;

}


vector<int> quicksort(vector<int>& nums ,  int l , int r) {

if(l > r){
    return nums ;
}
int pivot_index =  findPivot(nums , l , r);

 quicksort(nums , l , pivot_index - 1);
 quicksort(nums ,  pivot_index+1, r);

 return nums;

}






int main()
{

vector<int> nums  = {3, 5, 1, 7, 4, 9, 3};
vector<int> nums2  =  quicksort(nums ,  0 , nums.size()-1);

for(int n : nums2){
    cout << n << " " ;
}
    return 0;
}