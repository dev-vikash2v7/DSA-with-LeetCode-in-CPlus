#include <iostream>

using namespace std;



string reverseWord(string str){
  //Your code here
  string s ;
  int n = str.length();
  
  int start = 0  , end = n-1 ;

  while(start < end){
      char temp = str[start];
      str[start] = str[end] ;
      str[end] = temp ;
      start++;end--;
  }
  
//   for(int i = 0; i < n ; i++){
//       s.push_back(str[ n - i- 1]) ; 
//   }

  return str;
}

int main()
{
    string s = "geksh" ;
    cout << reverseWord(s) <<endl ;
     string p  ;
     for(int i = 0 ; i < s.length() ; i++){
         p[i] = s[i];
     }
    cout << p ;
return 0;
}