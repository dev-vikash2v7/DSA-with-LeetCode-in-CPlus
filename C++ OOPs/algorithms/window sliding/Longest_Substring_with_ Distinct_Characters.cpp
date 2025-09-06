#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestSubstringKDistinct(const string& str, int k) {
    int maxLength = 0, start = 0;
    unordered_map<char, int> charCount;

    for (int end = 0; end < str.size(); ++end) {
        charCount[str[end]]++;

        while (charCount.size() > k) {
            charCount[str[start]]--;
            if (charCount[str[start]] == 0) {
                charCount.erase(str[start]);
            }
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string str = "araaci";
    int k = 2;
    cout << "Length of longest substring with " << k << " distinct characters: " 
         << longestSubstringKDistinct(str, k) << endl;

    return 0;
}
