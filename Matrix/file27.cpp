//Find a specific pair in matrix
// An optimal method to find maximum value of mat[c][d]
// - ma[a][b] such that c > a and d > b
#include <bits/stdc++.h>
using namespace std;
#define N 5

// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N])
{
    vector<int> temp1(N), temp2(N);
    temp1[N - 1] = mat[N - 1][N - 1];

    // Fill temp1
    for (int j = N - 2; j >= 0; j--)
        temp1[j] = max(temp1[j + 1], mat[N - 1][j]);

    // stores maximum value
    int maxValue = INT_MIN;

    // Iterate over the remaining rows
    for (int i = N - 2; i >= 0; i--) {
        // Initialize the last element of temp2
        temp2[N - 1] = max(temp1[N - 1], mat[i][N - 1]);
        for (int j = N - 2; j >= 0; j--) {
            // update temp2 and maxValue
            maxValue
                = max(maxValue, temp1[j + 1] - mat[i][j]);
            temp2[j] = max(
                { mat[i][j], temp1[j], temp2[j + 1] });
        }
        // Set temp1 to temp2 for the next iteration
        temp1 = temp2;
    }

    // Return the maximum value
    return maxValue;
}

// Driver program to test above function
int main()
{
    int mat[N][N] = { { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 } };
    cout << "Maximum Value is " << findMaxValue(mat);

    return 0;
}