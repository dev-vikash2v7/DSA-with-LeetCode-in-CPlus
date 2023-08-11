#include <iostream>
using namespace std;

int main()
{
   string s = "this ,( is a ) & string!";
stringstream ss(s);
string word;

while (ss>>word)
{
    cout << word <<endl ;
}

    return 0;
}