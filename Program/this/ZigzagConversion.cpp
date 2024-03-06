#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  [[maybe_unused]] string convert(string s, int numRows) {
    // If there's only one row or the string is empty, return the input string
    // as is
    if (numRows == 1 || s.length() <= numRows) {
      return s;
    }

    vector<string> myString(
        numRows); // Use a vector of strings to represent rows

    int row = 0;
    int direction = 1; // Direction to move in the zigzag pattern (1 or -1)

    for (char c : s) {
      myString[row] += c; // Append the character to the current row
      row += direction;   // Move to the next row

      // Change direction if reaching the top or bottom row
      if (row == 0 || row == numRows - 1) {
        direction = -direction;
      }
    }

    // Concatenate rows to get the final converted string
    string convertedS;
    for (const string &rowStr : myString) {
      convertedS += rowStr;
    }

    return convertedS;
  }
};