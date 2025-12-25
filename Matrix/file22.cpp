// Search an element in a matrix
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rw = 0, col = cols - 1;

    while (rw < rows && col > -1)
    {
        int curr = matrix[rw][col];
        if (curr == target)
            return true;
        if (target > curr)
            rw++;
        else
            col--;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    if (searchMatrix(matrix, target))
    {
        cout << "true";
    }
    else
        cout << "false";
    return 0;
}