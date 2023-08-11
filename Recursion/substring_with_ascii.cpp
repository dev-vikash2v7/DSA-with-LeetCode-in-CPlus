#include <iostream>
#include <string>

using namespace std;

void subseq(string str , string ans)
{
    // cout << "before subseq() " << str << " | " << ans << endl;

    if(str.empty()) {

        cout <<"ans  ------- > "<< ans << endl;
        return ;
    }

    char ch = str[0] ;
    int code = ch ;

    // cout << ch << " " << code<<endl;



    string ros = str.substr(1);

subseq(ros , ans);
// subseq(ros ,ch +  ans);
subseq(ros ,  ans + ch);
subseq(ros ,  ans + to_string(code));

    // cout << "after subseq() " <<  str << " | " << ans << endl ;

}

int main()
{
    string str = "AB";
    subseq(str, "");

    return 0;
}