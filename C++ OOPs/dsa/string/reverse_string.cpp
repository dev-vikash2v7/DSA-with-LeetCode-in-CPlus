#include <iostream>
#include <vector>
using namespace std;

string func(string a) {

    if(a.length() <=0) return a ;

    return a[a.length() - 1] + func( a.substr(0, a.length() - 1));

}
int main()
{
    string a = "vikash";
cout << func(a)<<endl;

    return 0;
}