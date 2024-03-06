#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    static int lengthOfLongestSubstring(const std::string &s) {
        int max_length = 0;

        for (std::string::size_type i = 0; i < s.size(); i++) {
            std::unordered_set<char> charSet;
            int current_length = 0;

            for (std::string::size_type j = i; j < s.size(); j++) {
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
    std::cout << Solution::lengthOfLongestSubstring(s);
    std::cin.get();
}
