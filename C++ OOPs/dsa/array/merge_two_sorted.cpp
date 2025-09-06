#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& nums1 , vector<int>& nums2) {

vector<int> sorted ;  

int i = 0 , j = 0 ;

while (i<nums1.size() && j<nums2.size())
{
    if(nums1[i] < nums2[j]){
        sorted.push_back(nums1[i]);
        i++;
    }
    else{
         sorted.push_back(nums2[j]);
        j++;
    }
}

while (i<nums1.size())
{
     sorted.push_back(nums1[i]);
        i++;
}

while (j<nums2.size())
{
     sorted.push_back(nums2[j]);
        j++;
}

for(int num : sorted){
    cout << num << " " ;
}




}
int main()
{
   
vector<int> nums1  = {2, 5 , 7 , 10};
vector<int> nums2  = {1,3 , 4  ,6  , 9};
func(nums1 ,nums2);

    return 0;
}