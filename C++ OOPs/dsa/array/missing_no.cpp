#include <iostream>
#include <vector>
using namespace std;

int func(int n , vector<int>& nums) {

int total = n*(n+1)/ 2 ;

for(int i = 0 ; i < n - 1 ; i++){
    total -= nums[i];
}
return total ;


}
int main()
{
    int n = 10;

vector<int> nums  = {3, 5, 1, 7, 4, 9,  10 , 8 , 6};
cout <<  func(n , nums);

    return 0;
}