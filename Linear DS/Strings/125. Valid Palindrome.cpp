#include <iostream>
#include <vector>
using namespace std;

   bool isPalindrome(string s) {

            int l = 0 , r = s.size() - 1;

            while ( l <= r )
            {
                if(!isalnum(s[l]) )
                    l++;
                
                else if(!isalnum(s[r]))
                    r--;

                else if(tolower(s[l])  == tolower(s[r])){
                    l++;  r-- ;
                }
                else{
                  return false ;
                }

            }
            return true;
            
    }

    //    bool isPalindrome(string s) {

    //         string new_s = "";

    //         for (int i = 0; i <= s.size(); i++)
    //             if(isalnum(s[i])) new_s += tolower(s[i]);

    //         int l = 0 ;
    //         int r = new_s.size() - 1;

    //         while ( l <= r )
    //         {

    //              if(new_s[l]  == new_s[r]){
    //                 l++;
    //                 r-- ;
    //             }
    //             else 
    //               return false ;

    //         }
    //         return true;
            
    // }

int main()
{

string s = "A man, a plan, a canal: Panama";
cout <<  isPalindrome(s);

    return 0;
}