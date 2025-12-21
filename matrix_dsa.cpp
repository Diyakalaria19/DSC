//5 questions


#include <bits/stdc++.h>
using namespace std;

// 1. Search an Element in Matrix (Sorted rows & cols)
bool searchMatrix(vector<vector<int>>& matrix, int key) {
    int r = 0;
    int c = matrix[0].size() - 1;
    while(r < matrix.size() && c>= 0) {
        if(matrix[r][c] == key){
             return true;
        }
        else if(matrix[r][c] > key){
             c--;
        }
        else r++;
    }
    return false;
}

// 2. Find Row with Maximum Number of 1s
int rowWithMaxOnes(vector<vector<int>>& mat) {
    int maxRow = -1;
    int maxCount = 0;
    for(int i = 0; i < mat.size(); i++) {
        int countOne = 0;
        for(int j = 0; j < mat[i].size(); j++) {
            if(mat[i][j] == 1) countOne++;
        }
        if(countOne > maxCount) {
            maxCount = countOne;
            maxRow = i;
        }
    }
    return maxRow;
}

// 3. Rotate Matrix by 90 Degree (Clockwise)
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}


// 4. Median of Row-wise Sorted Matrix (Simple approach)
int findMedian(vector<vector<int>>& mat) {
    vector<int> temp;
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++)
            temp.push_back(mat[i][j]);
    }
    sort(temp.begin(), temp.end());
    return temp[temp.size() / 2];
}

// 5. Kth Smallest Element in Matrix
int kthSmallest(vector<vector<int>>& mat, int k) {
    vector<int> temp;
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++)
            temp.push_back(mat[i][j]);
    }
    sort(temp.begin(), temp.end());
    return temp[k - 1];
}
