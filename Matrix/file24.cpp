//Find row with maximum no. of 1's
#include <bits/stdc++.h>
using namespace std;


int rowWithMax1s(vector<vector<bool>>& mat) {
    int maxRow = -1, row = 0;
    int R = mat.size();
    int C = mat[0].size();
    int col = C - 1;

    // Move till we are inside the matrix
    while (row < R && col >= 0) {
        // If the current value is 0, move down to the next row
        if (mat[row][col] == 0) {
            row += 1;
        }

        else {
            maxRow = row;
            col -= 1;
        }
    }
    return maxRow;
}

// Driver Code
int main() {
    vector<vector<bool>> mat = { { 0, 0, 0, 1 },
                                 { 0, 1, 1, 1 },
                                 { 1, 1, 1, 1 },
                                 { 0, 0, 0, 0 } };

    cout << "Index of row with maximum 1s is "
         << rowWithMax1s(mat);

    return 0;
}