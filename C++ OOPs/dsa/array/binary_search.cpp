#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& nums , int n , int l , int r ){

    if(l > r) return -1;

    int mid = (l+r) / 2;

    if(nums[mid] > n){
       return binary_search(nums ,n , l , mid - 1);
    }
    else if(nums[mid] < n){
      return  binary_search(nums ,n , mid  + 1, r );
    }
    return mid;
}

int func(vector<int>& nums , int n) {

cout << binary_search(nums , n , 0 , nums.size()-1);

}

int main()
{
  

vector<int> nums  = {4 , 8 , 10 , 11,12 , 14};
int n = 11 ;
func(nums , n);

    return 0;
}