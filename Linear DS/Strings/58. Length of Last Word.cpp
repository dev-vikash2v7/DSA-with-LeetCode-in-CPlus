#include <iostream>
#include <vector>
using namespace std;

  int lengthOfLastWord(string s) {
        
        int length = 0 ;

        for (int i = s.size()-1; i >= 0; i--)
        {
           
            if(s[i] != ' '){
                while ( i>= 0 && s[i] != ' ' )
                {
                    /* code */
                    length++;
                    i--;
                }
                break;
            }
           
        }

        return length ;
        
    }


int main()
{
    

string s = "a" ;
cout <<  lengthOfLastWord(s) << endl;

    return 0;
}