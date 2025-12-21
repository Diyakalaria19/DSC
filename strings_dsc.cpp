

#include <bits/stdc++.h>
using namespace std;

// 16. Reverse string
string reverseString(string s) {
    int i = 0, j = s.length()-1;
    while(i < j) {
        swap(s[i],s[j]);
        i++; 
        j--;
    }
    return s;
}

// 17. Palindrome string
bool isPalindrome(string s) {
    int i = 0, j = s.length()-1;
    while(i < j) {
        if(s[i] != s[j]){
             return false;
        }
        i++;
         j--;
    }
    return true;
}

// 18. Roman to Integer
int romanToInt(string s) {
    map<char,int> mp;
    mp['I']=1; mp['V']=5; mp['X']=10;
    mp['L']=50; mp['C']=100; mp['D']=500; mp['M']=1000;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i+1 < s.size() && mp[s[i]] < mp[s[i+1]])
            ans -= mp[s[i]];
        else ans += mp[s[i]];
    }
    return ans;
}

// 19. Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string pref = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        while(strs[i].find(pref) != 0) {
            pref.pop_back();
            if(pref.empty()) return "";
        }
    }
    return pref;
}

// 20. Valid shuffle
bool isValidShuffle(string s1, string s2, string s3) {
    if(s1.length() + s2.length() != s3.length()){
         return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(s3.begin(),s3.end());
    string temp =s1 + s2;
    sort(temp.begin(),temp.end());
    return temp == s3;
}

// 21. Count and Say
string countAndSay(int n) {
    string res = "1";
    while(--n) {
        string current = "";
        for(int i = 0; i < res.length(); i++) {
            int count = 1;
            while(i+1 < res.length() && res[i] == res[i+1]) {
                count++; i++;
            }
            current += to_string(count) +res[i];
        }
        res = current;
    }
    return res;
}

// 22. First repeated word
string firstRepeatedWord(vector<string>& words) {
    unordered_set<string> s;
    for(string w : words) {
        if(s.count(w)){
             return w;
        }
        s.insert(w);
    }
    return "-1";
}

// 23. Binary string alternate flips
int minFlips(string s) {
    int flip1 = 0, flip2 = 0;
    for(int i = 0; i < s.length(); i++) {
        if(i % 2 == 0) {
            if(s[i] != '0'){
                 flip1++;
            }
            if(s[i] != '1'){
                 flip2++;
            }
        } else {
            if(s[i] != '1'){
                 flip1++;
            }   
            if(s[i] != '0'){
                 flip2++;
            }
        }
    }
    return min(flip1,flip2);
}

// 24. Split binary string
int splitBinary(string s) {
    int zero = 0, one = 0, count = 0;
    for(char c : s) {
        if(c == '0'){
             zero++;
        }
        else one++;
        if(zero ==one){
             count++;
        }
    }
    if(zero != one) return -1;
    return count;
}

// 25. Print subsequences
void printSubseq(string s, string out, int idx) {
    if(idx ==s.length()) {
        cout<<out<<endl;
        return;
    }
    printSubseq(s,out,idx+1);
    printSubseq(s,out+s[idx], idx+1);
}

// 26. Print permutations
void permute(string s,int l,int r) {
    if(l == r) {
        cout<<s<<endl;
        return;
    }
    for(int i = l;i <= r; i++) {
        swap(s[l],s[i]);
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }
}

// ===================== STRINGS =====================

// 6. Longest Valid Parentheses
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            st.push(i);
        else {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans = max(ans, i - st.top());
        }
    }
    return ans;
}

// 7. Edit Distance
int editDistance(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}

// 8. Word Break
bool wordBreak(string s, vector<string>& dict) {
    unordered_set<string> st(dict.begin(), dict.end());
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && st.count(s.substr(j, i-j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

// 9. Longest Palindromic Substring
string longestPalindrome(string s) {
    int start = 0, maxLen = 1;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
        l = i; r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }
    return s.substr(start, maxLen);
}

// 10. Longest Repeating Subsequence
int longestRepeatingSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == s[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
