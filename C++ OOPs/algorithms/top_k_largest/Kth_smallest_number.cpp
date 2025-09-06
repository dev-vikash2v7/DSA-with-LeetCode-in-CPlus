#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void func(priority_queue<int ,vector<int>,greater<int>>  nums , int k ) {

int a = k;
if(k> nums.size()){
    cout << "not valid k";
}

while (k != 1)
{
    nums.pop();
    k--;
}

cout << a << " th smallest number is " << nums.top() <<endl;


}
int main()
{

vector<int> nums  = {3, 5, 1, 7, 4, 9, 2};

priority_queue<int ,vector<int>, greater<int>> pq (nums.begin() , nums.end());



int k = 4 ;
func(pq , k);

    return 0;
}