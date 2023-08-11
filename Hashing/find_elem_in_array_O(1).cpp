// given an array contains both +ve and -ve numbers ,
// elements are in the range of -max to +max
// task : to search if element is present in O(1)
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

bool hashMatrix[2][MAX + 1];

bool search( int x )
{
    if(x >=0 ){
        return hashMatrix[0][x] == true ;
        }

    else{
        return hashMatrix[1][abs(x)] == true ;

    }
    
}


void insert(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] >= 0 ? hashMatrix[0][arr[i]] = true : hashMatrix[1][abs(arr[i])] = true;
    }
}

int main()
{
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr) / 4;
    insert(arr, n);

    if(search(-5)){
cout << "element found ";
    }
    else{
cout << "not element found ";

    }


    return 0;
}