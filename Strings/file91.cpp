
//Print all Subsequences of a string.
#include <bits/stdc++.h>
using namespace std;

// Function to print all the power set
void printPowerSet(string &s) {
    int n = pow(2, s.size());
    
    for (int counter = 0; counter < n; counter++) {
        for (int j = 0; j < s.size(); j++) {
          
            // Check if jth bit in the counter is set
            if (counter & (1 << j))
                cout << s[j];
        }
        cout << endl;
    }
}

/* Driver code */
int main() {
    string s = "ab";
    printPowerSet(s);
    return 0;
}
