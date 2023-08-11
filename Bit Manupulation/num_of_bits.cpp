#include <bits/stdc++.h>

using namespace std;

void bitrep(int n)
{
    if (n == 0 || n == 1)
    {
        cout << n;
        return;
    }
    bitrep(n / 2);
    cout << n % 2;
}


void countbits(int a ){
   
int c_1 = 0 ;
int c_0 = 0 ;

  while(a){

    if(a % 2  == 1){
        c_1++;
    }
    else{
        c_0++;
    }
    a = a >> 1 ;
  }

cout << "count of 1's " << c_1  << endl;
cout << "count of 0's " << c_0   << endl;

}

int main()
{
    int a = 22 ;

    bitrep(a);
    cout << endl;
  

countbits(a );


    return 0;
}