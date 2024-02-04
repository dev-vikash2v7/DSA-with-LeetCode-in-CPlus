#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

   int hIndex(vector<int>& citations) {
        
       sort(citations.begin() , citations.end() , greater<int>());

       int maxHIndex = citations[0];

       for (int i = 1; i < citations.size(); i++)
       {
            if (citations[i] >= i + 1) {
                   maxHIndex = i + 1;
        }    else {
            break;
        }
       }
       return maxHIndex;
       
    }


int main()
{
    

vector<int> nums  = {3,0,6,1,5};
cout <<hIndex(nums)<<endl;

    return 0;
}