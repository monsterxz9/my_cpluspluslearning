#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    [[maybe_unused]] static string longestPalindrome(const string &s) {
        size_t n = s.length();
        if (n <= 1) {
            return s;
        }

        // Create a 2D DP table to store whether substrings are palindromic
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromic
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        int start = 0;     // Start index of the longest palindromic substring
        int maxLength = 1; // Length of the longest palindromic substring

        // Check substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check substrings of length 3 or more
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index of the current substring

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
