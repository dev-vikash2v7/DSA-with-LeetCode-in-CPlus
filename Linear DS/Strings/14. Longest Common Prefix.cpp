#include <iostream>
#include <vector>
using namespace std;

//   string longestCommonPrefix(vector<string>& strs) {

//         if(strs.empty() ) return "";

//         string common_prefix = strs[0];

//         for (int i = 1; i < strs.size(); i++)
//         {
//             /* code */
//             string current_prefix = "" ;
//             int j = 0 ;

//             while ( j < common_prefix.length() && j < strs[i].length() &&   common_prefix[j] == strs[i][j])
//             {
//                 /* code */
//                 current_prefix += common_prefix[j];
//                 j++;
//             };

//             common_prefix = current_prefix;

            
//         }

//         return common_prefix;
//     }

    string longestCommonPrefix(vector<string>& v) {
        
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];

        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }

int main()
{
  
vector<string> nums  = {"flower","flow","flight"};

cout<<longestCommonPrefix(nums)<< endl;

    return 0;
}