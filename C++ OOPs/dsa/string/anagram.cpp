#include <iostream>
#include <vector>
using namespace std;

int func(string s1 , string s2) {

    if(s1.size() != s2.size()) return 0 ;

    int arr[26] = {0};



    for(int i = 0 ; i < s1.size() ;i++){
        arr[ s1[i] - 'a' ]++;
        arr[ s2[i] - 'a' ]--;
    };

      for(int a : arr){
        if(a != 0) return 0;
    };

    return 1;



}
int main()
{
  string s1 = "ate";
  string s2 = "eat";
cout <<  func(s1,s2);

    return 0;
}