#include <bits/stdc++.h>
using namespace std;
bool allsame(string s) {
    size_t diffIndex = 1;
    while (diffIndex < s.size() && s[diffIndex] == s[0]) {
        ++diffIndex;
    }
    return diffIndex == s.size();
}
int main() {
    string s;
    cin >> s;
    // Find the first character that is different from the first character
    size_t diffIndex = 1;
    while (diffIndex < s.size() && s[diffIndex] == s[0]) {
        ++diffIndex;
    }
    // If all characters are the same, no solution is possible
    if (diffIndex == s.size() || s.size() <= 3) {
        cout << -1 << endl;
    } else if (s.size() % 2 == 1 && allsame(s.substr(0, s.size() / 2 - 1))) {
        cout << -1;
    } else {
        // Swap the first two different characters
        if (s.size() % 2 == 1) {
            swap(s[0], s[diffIndex]);
            swap(s[s.size() - 1], s[2 * (s.size() / 2 + 1) - (diffIndex + 1) - 1]);
            // Output the modified string
            cout << s << endl;
        } else {
            swap(s[0], s[diffIndex]);
            swap(s[s.size() - 1], s[2 * s.size() / 2 + 1 - (diffIndex + 1) - 1]);
            // Output the modified string
            cout << s << endl;
        }
    }
    return 0;
}