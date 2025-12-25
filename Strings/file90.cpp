//Find Longest Recurring Subsequence in String
// C++ program to find longest
// repeating subsequence
// using space optimization

#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string& s) {
  
    int n = s.length();

    // Create a 1D array for the current row
    vector<int> curr(n + 1, 0);

    // Variable to store dp[i-1][j-1] for each (i, j)
    // This helps to track the diagonal value from the previous iteration
    int match = 0;

    for (int i = 1; i <= n; i++) {

        // Reset match to 0 for the new row
        match = 0;

        for (int j = 1; j <= n; j++) {

            // Store the current cell value before updating
            int tmp = curr[j];

            // If characters match and indices are different
            if (s[i - 1] == s[j - 1] && i != j) {
                // Add 1 to the diagonal value
                curr[j] = 1 + match;
            }
            else {
                // Take the maximum value between left and top cells
                curr[j] = max(curr[j], curr[j - 1]);
            }
            // Update match to the previous cell value
            match = tmp;
        }
    }

    return curr[n];
}

int main() {

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;
    return 0;
}