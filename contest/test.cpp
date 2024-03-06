#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int to_val(string s){
        int num = 0;
        for (char i : s) {
            num = 10 * num + (i - '0');
        }
        return num;
    }

    [[maybe_unused]] static int reverse(int x) {
        if (x == 0) return x;
        bool pn = true;
        if (x < 0) {
            pn = false;
            x = abs(x);
        }
        string s = to_string(x);
        string s1 = string(s.rbegin(), s.rend());
        if (s1 > "2147483647") { return false; }
        else {
            if (pn) {return to_val(s1);} else {}
        }
    }
};