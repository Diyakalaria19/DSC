//Stack Permutations (Check if an array is stack permutation of other)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool checkPerm(vector<int>& a, vector<int>& b) {
    stack<int> st;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        
        // Push top of a[] to stack
        st.push(a[i]);

        // Keep popping from stack while it
        // matches front of the output queue
        while (!st.empty() && st.top() == b[j]) {
            st.pop();
            j++;
        }
    }

    return (j == b.size());
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};

    cout << (checkPerm(a, b) ? "true" : "false") << endl;

    return 0;
}