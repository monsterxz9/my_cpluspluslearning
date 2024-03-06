#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    vector<string> a;
    string b;
    while (cin >> b) {
        a.push_back(b);
    }
    int cnt = 0;
    int pos = -1; // Initialize pos to -1 to indicate no matching string found
    for (int index = 0; index < a.size(); ++index) {
        string &currentString = a[index];
        if (currentString.size() == s.size()) {
            bool isEqual = true;
            for (int j = 0; j < s.size(); ++j) {
                if (tolower(s[j]) != tolower(currentString[j])) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                if (cnt == 0) {
                    pos = index; // Update pos to current index
                }
                cnt++;
            }
        }
    }

    if (cnt != 0)
        cout << cnt << ' ' << pos;
    else
        cout << -1;
    return 0;
}

// a-z 97-122
// A-Z 65-90
