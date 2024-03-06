#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(const std::string &s) {
        int max_length = 0;

        for (int i = 0; i < s.size(); i++) {
            std::unordered_set<char> charSet;
            int current_length = 0;

            for (int j = i; j < s.size(); j++) {
                if (charSet.find(s[j]) == charSet.end()) {
                    charSet.insert(s[j]);
                    current_length++;
                } else {
                    break;
                }
            }

            max_length = std::max(max_length, current_length);
        }

        return max_length;
    }
};


int main() {
    std::string s;
    std::cin >> s;
    Solution::lengthOfLongestSubstring(s);

}
