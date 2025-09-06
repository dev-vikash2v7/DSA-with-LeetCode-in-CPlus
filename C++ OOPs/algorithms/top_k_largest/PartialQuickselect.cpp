#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int partition(vector<int>& nums , int l , int r){
    
    int pivot = nums[r];
    int pivot_i = l - 1;

    for(int i = l ; i< r ;i++){
        if(pivot <= nums[i]){
            pivot_i++;
            swap(nums[pivot_i] , nums[i]);
        }
    }
    swap(nums[pivot_i + 1] , nums[r]);
    return pivot_i + 1;
    
}

void klargest(vector<int>& nums , int k , int l , int r) {


    if(l > r) return ;

    int pivot_i = partition(nums, l , r);

    if(pivot_i == k + 1){
        return ;
    }

if(pivot_i > k){

    klargest(nums , k , l , pivot_i-1);
}
else{

    klargest(nums , k ,  pivot_i+1 , r);
}




}

int main()
{
 
vector<int> nums  = {3, 5, 1, 7, 4, 9, 6};
int k = 3;
 klargest(nums , k, 0 , nums.size()-1);

vector<int> result(nums.begin(), nums.begin() + k);

sort(result.begin() ,result.end() , greater<int>());

 for(int n : result){
    cout << n << " " ;
}
    return 0;
}