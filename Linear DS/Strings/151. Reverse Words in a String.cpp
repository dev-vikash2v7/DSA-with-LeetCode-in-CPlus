#include <iostream>
#include <vector>
using namespace std;

 string reverseWords(string s) {
        
        string res = "" ;

        for (int i = 0; i < s.size(); i++)
        {
            string current_res = "" ;

           
            while(i< s.size() && s[i] != ' '){
                    current_res += s[i];
                    i++;
            }

            if(!current_res.empty())
                res = " " + current_res + res;
        }

        if (!res.empty() && res[0] == ' ') 
           res = res.substr(1);

        return res;
    };


    // string reverseWords(string s) {

    //     string c="";
    //     string ans="";

    //     for(int i=s.length()-1;i>=0;i--){

    //         if(s[i]!=' '){

    //             c+=s[i];
    //         }else{
    //             if(c!=""){
    //                reverse(c.begin(),c.end());
    //             ans+=c;
    //             ans+=" ";
    //             c=""; 
    //             }
                
    //         }
    //     }
    //     if (c != "") {
    //         reverse(c.begin(), c.end());
    //         ans += c;
    //     }

    //     if(ans[ans.length()-1]==' '){
    //         ans.erase(ans.length()-1,1);
    //     }
    //     return ans;
        
    // }

int main()
{
string s = "   the sky is blue   ";
cout <<  reverseWords(s) << endl;

    return 0;
}