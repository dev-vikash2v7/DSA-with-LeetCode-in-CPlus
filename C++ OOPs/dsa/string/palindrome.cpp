#include <iostream>
#include <vector>
using namespace std;

int func(string a) {

    if(a.length() == 1) return 1 ;
    if(a.length() == 2) return a[0] == a[1] ;

    if( a[0] == a[a.length() - 1]){
        return func(a.substr(1, a.length() - 2));
    }
    else return 0;


}
int main()
{
   string a = "abcbcba";

cout <<  func(a)<<endl;

    return 0;
}