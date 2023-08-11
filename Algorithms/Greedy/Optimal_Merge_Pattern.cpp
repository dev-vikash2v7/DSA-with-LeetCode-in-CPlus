    #include <bits/stdc++.h>
using namespace std;
 
int OptimalMergePatternResult(int arr[] , int n){
priority_queue<int , vector<int> , greater<int> >pq;

for(int i = 0 ; i < n ; i++)
    pq.push(arr[i]);

while (pq.size() > 1)
{
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();

    pq.push(a+b);
    cout <<" " << a << " " << b <<" " << a*b << endl;
}

return pq.top();

}


int main(){

    int n = 3 ;
    int arr[n] = {6  , 2 , 4};

    int res = OptimalMergePatternResult(arr , n);
    cout << "minimum sum = " << res << endl;
 
return 0;
}