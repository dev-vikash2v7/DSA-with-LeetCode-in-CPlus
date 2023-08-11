#include <iostream>

using namespace std;

string move_ch(string s , char key){

if(s.empty()) return "";

char ch = s[0] ;
cout << ch << " ----- " << s << endl ;

string ros = move_ch(s.substr(1) , key);

cout << ros << endl;

if(ch == key){
    return ros + ch;
}

return ch + ros ;

}

int main()
{
    string s = "axxbdxcefxhix";
    string result = move_ch(s , 'x') ;

    cout << result << endl;
return 0;
}