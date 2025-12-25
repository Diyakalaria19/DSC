// Spiral traversal on a Matrix
#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int m = mat.size();    // number of rows
    int n = mat[0].size(); // number of columns
    vector<int> res;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            res.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    vector<int> res = spirallyTraverse(mat);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}