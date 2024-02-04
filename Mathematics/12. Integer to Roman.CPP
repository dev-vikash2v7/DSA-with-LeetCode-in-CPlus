#include <iostream>
#include <vector>

using namespace std;

//  string intToRoman(int num) {

//         vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};


//         string res = "";

//         for (int i = 0; i < values.size(); i++) {

//                 while (num >= values[i] )
//                 {
//                     res += symbols[i];
//                     num -= values[i];
//                 }
                
//     }

//         return res;
//     }

 string intToRoman(int num) {

       string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};


        int thousands_place = num / 1000 ;
        num %= 1000 ; 
        int hundered_place = num / 100 ;
        num %= 100 ; 
        int tenth_place = num / 10 ;
        num %= 10 ; 
        int ones_place = num  ;

        string res = thousands[thousands_place] + hundreds[hundered_place]  + tens[tenth_place] + ones[ones_place];

        return res;
    }


int main()
{
    int n = 19;
   
cout <<  intToRoman(n);

    return 0;
}