//The celebrity Problem
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();
    stack<int> st;

    // push everybody in stack
    for (int i = 0; i < n; i++)
        st.push(i);

    // find a potential celebrity
    while (st.size() > 1) {

        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        // if a knows b
        if (mat[a][b]) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }

    // potential candidate of celebrity
    int c = st.top();
    st.pop();

    // Check if c is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        if(i == c) continue;

        // if any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}

int main() {
    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};
    cout << celebrity(mat);
    return 0;
}