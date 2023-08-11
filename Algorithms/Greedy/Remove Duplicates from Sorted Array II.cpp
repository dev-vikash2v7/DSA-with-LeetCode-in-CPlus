    #include <bits/stdc++.h>
using namespace std;
 
  int removeDuplicates(vector<int>& nums) {
        int c = 1 ;
        int i = 0 ;

        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[i] == nums[j] && c < 2){
                i++ ;
                c++;
                
            }
            else {
                  nums[i] = nums[j] ;
                // swap(nums[i] , nums[j]);
                  c = 1 ;
            }
        }

        for(int i : nums) cout << i << " ";
cout << endl ; 
         return i+1 ;
    }
    


int main(){
    vector<int> arr = {1,1,1,2,2,3};
    int res = removeDuplicates(arr );
    cout <<   res << endl;
return 0;
}