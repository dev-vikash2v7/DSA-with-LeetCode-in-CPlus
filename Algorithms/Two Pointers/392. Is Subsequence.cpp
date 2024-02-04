#include <iostream>
#include <vector>
using namespace std;

   bool isSubsequence(string s, string t) {
        
        int  j = 0;

        for (size_t i = 0; i < t.size(); i++)
        {
            /* code */
            if( j >= s.size()  ) return true ;

            if(s[j] == t[i]) {
                j++;
            }
        }

        return j >= s.size(); 
        
    }

int main()
{

cout <<  isSubsequence("axc" , "ahbgdc");

    return 0;
}