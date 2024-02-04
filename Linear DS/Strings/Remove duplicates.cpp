#include <iostream>
#include <unordered_set>

void removeDuplicatesInPlace(std::string& s) {
    std::unordered_set<char> seenChars;
    size_t writeIndex = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        if (seenChars.find(s[i]) == seenChars.end()) {
            seenChars.insert(s[i]);
            s[writeIndex++] = s[i];
        }
    }

    // Trim the string to the length with unique characters
    s.resize(writeIndex);
}

int main() {
    // Example usage
    std::string input = "leetcode";
    removeDuplicatesInPlace(input);

    std::cout << "Original String: leetcode" << std::endl;
    std::cout << "String with Duplicates Removed: " << input << std::endl;

    return 0;
}
