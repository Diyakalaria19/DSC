//Minimum sum of squares of character counts in a given string after removing “k” characters.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int minValue(string &s, int k) {
    
    int n = s.length();
    int alphabetCount[26] = {0};
    
    int maxi = 0;
    
    // Count frequency of each character
    for (char c : s) {
        alphabetCount[c - 'a']++;
        maxi = max(alphabetCount[c-'a'], maxi);
    }
    
    // frequency bucket 
    vector<int> freq(maxi+1, 0);
    
    int maxFreq = 0;
    
    // Fill frequency bucket
    for (int i = 0; i < 26; i++) {
        if (alphabetCount[i] > 0) {
            freq[alphabetCount[i]]++;
            maxFreq = max(maxFreq, alphabetCount[i]);
        }
    }

    // Reduce frequencies using k removals
    while (k > 0 && maxFreq > 0) {
        int countAtMax = freq[maxFreq];
        if (countAtMax <= k) {
            k -= countAtMax;
            freq[maxFreq - 1] += countAtMax;
            freq[maxFreq] = 0;
            maxFreq--;
        } else {
            freq[maxFreq] -= k;
            freq[maxFreq - 1] += k;
            k = 0;
        }
    }

    int result = 0;
    for (int i = 1; i <= maxi; i++) {
        result += i * i * freq[i];
    }

    return result;
}

// Driver code
int main() {
    
    string s = "abbccc";
    int k = 2;
    cout << minValue(s, k) << endl;
    return 0;
}