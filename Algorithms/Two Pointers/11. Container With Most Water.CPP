#include <iostream>
#include <vector>
using namespace std;

 int maxArea(vector<int>& height) {
        
        int max_area = 0 ;
        int l = 0  , r = height.size() - 1;

        while (l < r)
        {
            int minH = min(height[l] , height[r]);
            int range = r - l ;

            max_area = max(max_area , minH * range) ;


            if (height[l] < height[r])
            {
                l++;
            }
            else r--;
            
        }
        

        return max_area;
    }

int main()
{
 

vector<int> height  = {1,8,6,2,5,4,8,3,7};
cout <<  maxArea(height)  << endl;

    return 0;
}