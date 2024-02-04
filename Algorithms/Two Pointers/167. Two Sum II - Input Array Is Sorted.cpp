#include <iostream>
#include <vector>
using namespace std;

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0 , j = numbers.size() -1  ;

        while (i <= j)
        {
            if(numbers[i] + numbers[j] == target) return {i + 1 , j+1};

            else if(numbers[i] + numbers[j] > target) j-- ;

            else i++ ;
        }

        return {-1,-1};
        
    }

int main()
{
    

vector<int> nums  = {2,7,11,15};

 vector<int> res =   twoSum(nums , 9);

for (size_t i = 0; i < res.size(); i++)
{
   cout << res[i] <<endl;
}

    return 0;
}