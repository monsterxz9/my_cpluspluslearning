#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int reverse(int x) {
        if (x == 0)
            return x;

        bool isNegative = (x < 0);
        int reversed = 0;

        x = abs(x);

        while (x > 0) {
            int digit = x % 10;

            // Check for overflow before updating reversed
            if (reversed > (INT_MAX - digit) / 10) {
                return 0;
            }

            reversed = reversed * 10 + digit;
            x /= 10;
        }

        if (isNegative) {
            reversed = -reversed;
        }

        return reversed;
    }
};
