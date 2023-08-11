#include <iostream>

using namespace std;

void find_element(int arr[] ,  int k ){
    int range = 50 ;

    int l = 0 , h = 1 ;

    while (arr[h] < k)
    {
        l = h ;
        h *= 2 ; 
    }
    cout << l << " " << h <<endl;

    while (l <= h)
    {
        int m = (l+h)/2;

        if(arr[m] == k){
            cout <<"find " <<  m <<  endl;
            return ;
        }
        else if(k < arr[m] ){
             h = m - 1;
        }
        else{
            l = m + 1;
        }
    }

    
    
    
cout<<"no find\n";


}
int main()
{
    int arr[1000] ;

    for(int i = 0 ; i < 5000 ; i++){
        arr[i] = i;
    }
find_element(arr ,  999);


return 0;
}