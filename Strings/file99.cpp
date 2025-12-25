//Count All Palindromic Subsequence in a given String.
#include <bits/stdc++.h>
using namespace std;

int countPS(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every single character is a palindrome,
    // so initialize diagonal elements
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the table for substrings of length greater than 1
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            } else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    string s = "geeksforgeeks";
    cout << countPS(s);
}