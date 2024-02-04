#include <iostream>
#include <vector>
using namespace std;

 int strStr(string haystack, string needle) {

         size_t ans =    haystack.find(needle);

        if (ans != std::string::npos) {
        return ans;
    }
    
     return -1;
    }

int main()
{

cout <<  strStr("saadbutsad" , "sad");

    return 0;
}