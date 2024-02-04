#include <iostream>
#include <unordered_map>
using namespace std;

  int romanToInt(string s) {

     unordered_map<char,int> roman_values  =  {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        } ;

int ans = 0 ; 
int n = s.size();

        for(int i = 0 ; i < n - 1 ; i++){

            if( roman_values[s[i]] >= roman_values[s[i+1]])
                    ans += roman_values[s[i]];
            else 
                  ans -=  roman_values[s[i]] ;

                
        }

        return ans + roman_values[s[n-1]];
    }

int main()
{
    
    string s  = "MCMXCIV";
cout <<  romanToInt(s) << endl;

    return 0;
}