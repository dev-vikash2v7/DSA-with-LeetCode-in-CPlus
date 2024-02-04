#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

       int n = nums.size();
       vector<int> answer(n,1) ;

        int right_product = nums[n-1] ; 
       
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }  
    
        for (int i = n-2; i >= 0 ; i--) {
            answer[i] = right_product * answer[i];
            right_product *= nums[i];
        }  

        return answer;  

};;
// vector<int> productExceptSelf(vector<int>& nums) {

//        int n = nums.size();
//        vector<int> left_product(n,1) ;
//        vector<int> right_product(n,1) ;
//        vector<int> answer(n,1) ;

//         left_product[0] =  right_product[n-1] = 1;

       
//         for (int i = 1; i < n; i++) {
//             left_product[i] = left_product[i-1] * nums[i-1];
//         }  
    

//         for (int i = n-2; i >= 0 ; i--) {
//             right_product[i] = right_product[i+1] * nums[i+1];
//         }  

//          for (int i = 0; i < n ; i++) {
//             answer[i] = left_product[i] * right_product[i];
//         }  

//         return answer;  

// };;


int main()
{
    
vector<int> nums  = {1,2,3,4};

vector<int> result =  productExceptSelf(nums); 

    for (int i = 0; i < result.size(); i++) {
cout << result[i] << " ";
    }
    return 0;
}