#include <iostream>
#include <vector>
using namespace std;

 string convert(string s, int numRows) {

    if(numRows == 1 || s.length() <= numRows ) return s;
        
    string res = "";
    vector<string>zigzag_map(numRows);
    int current_row = 0 ;
    int isDown = false ; 

    for (int i = 0; i < s.size(); i++)
    {
             zigzag_map[current_row] += s[i] ;

            if( current_row == 0 || current_row == numRows - 1){
                isDown = !isDown ;
            }

             current_row += isDown ? 1 : -1;
    }

     for (int i = 0; i < zigzag_map.size(); i++)
        res += zigzag_map[i];

return res;
    
    }
    
int main()
{
   
string s  = "HELLOWORLD";
cout <<  convert(s , 4);

    return 0;
}