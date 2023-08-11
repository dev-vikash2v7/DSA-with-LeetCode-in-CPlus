    #include <bits/stdc++.h>
using namespace std;

    int removeElement(vector<int>& nums, int val) {
        
        int i = -1 ;
        for ( int  j = 0 ; j < nums.size() ; j++){
             if(nums[j] != val){
                i++ ;
                swap(nums[i] , nums[j]);
                
             }
             
         }

         for(int i : nums) cout << i << " ";
cout << endl ; 
        return i+1;
    }


int main(){

    int val = 2 ;
    vector<int> arr = {0,1,2,2,3,0,4,2};
    int res = removeElement(arr , val);
    cout <<   res << endl;
 
return 0;
}