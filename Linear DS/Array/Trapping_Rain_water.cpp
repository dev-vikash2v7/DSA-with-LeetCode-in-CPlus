#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}
int max_(int a, int b) { return a > b ? a : b; }
int min_(int a, int b) { return a < b ? a : b; }

int RainWater(int arr[], int n)
{
    int *left = new int[n], *right = new int[n];
    
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];


    int water = 0 ;

    for (int i = 1; i < n; i++)
    {

        left[i] = max_(arr[i], left[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {

        right[i] = max_(arr[i], right[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        // cout << left[i] << " " << right[i] << endl;
        water +=  min_( left[i], right[i] ) - arr[i] ; 
    }
    return water;
}


int main()
{

    int blocks[] = {3, 1, 2, 4, 0, 1, 3, 2};

    int area = RainWater(blocks, 8);
    cout << area << endl;
    return 0;
}

/*
 3 , 1, 2 , 4 , 0 , 1 , 3 , 2

 [3,4]
 [3,4]
 [3,4]
 [4,4]
 [4,3]
 [4,3]
 [4,3]
 [4,2]
*/