#include <bits/stdc++.h>

using namespace std;

void show(vector<int> res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

// void longest_sub(string str){
//     int start = -1 ;
//     int longest = 0 ;
//     vector<int>dict(256,-1);

//     for(int end = 0 ; end < str.size() ; end++){
//                 if(dict[str[end]] > start ){
//                     start = dict[str[end]]  ;
//                 }
//                 dict[str[end]] = end ;
//                 longest =longest >  end - start ? longest : end  - start  ;
//     cout << longest << endl;
//     }

//     // show(dict);
// }
void longest_sub(string str)
{
    int start = 0;
    int longest = 0;
    set<char> s;

    for (int end = 0; end < str.size();)
    {
        // if not find
        if (s.find(str[end]) == s.end())
        {
            longest = longest > end - start + 1 ? longest : end - start + 1;
            s.insert(str[end]);
            end++;
        }
        else
        {
            // if find
            s.erase(str[start]);
            start++;
        }
        //  end,start,longest
    }
    cout << longest << endl;

    // show(dict);
}
int main()
{
    // string s = "abcabcbb";
    string s = "geeksforgeeks";
    longest_sub(s);
    return 0;
}

/*
s = "bbbb"
ans = 1

s = pwwkew
wke

idea
...
-while iterating mark the position of each chr\
-at ith char check the prev occurance and decide the start of the substrin accordingly

abcabcbb

end,start,longest,s
0,  0,    1   a
1,  0,    2   ab
2,  0,    3   abc
3,  1     3   bc
3,  1     3   bca
4,  2     3   ca
4,  2     3   cab
5,  3     3   ab
5,  3     3   abc
6,  4     3   ac
6,  4     3   acb

geeksforgeeks

    end,start,longest,s
 g   0,  0,    1   g
 e   1,  0,    2   ge

 e   2,  1,    2   e
 e   2,  2,    2   
 e   2,  2,    2   e

 k   3,  2     2   ek
 s   4,  2     3   eks
 f   5,  2     4   eksf
 o   6,  2     5   eksfo
 r   7,  2     6   eksfor
 g   8,  2     7   eksforg
 e   9,  3     7   ksforg
 e   9,  3     7   ksforge
 e   6,  4     3   acb
 e   6,  4     3   acb
 e   6,  4     3   acb
 k   6,  4     3   acb
 s   6,  4     3   acb
*/