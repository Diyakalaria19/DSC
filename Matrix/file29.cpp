
//Kth smallest element in a row-cpumn wise sorted matrix
#include <iostream>
#include <vector>
using namespace std;

// function to count the number of elements 
// less than or equal to x
int countSmallerEqual(vector<vector<int>>& mat, int x) {
    int n = mat.size();
    int count = 0;
    int row = 0;
    int col = n - 1;

    // traverse from the top-right corner
    while (row < n && col >= 0) {
        if (mat[row][col] <= x) {
            
            // if current element is less than 
            // or equal to x, all elements in this
            // row up to the current column are <= x
            count += (col + 1);
            row++;
        } 
        else{
            // move left in the mat
            col--;
        }
    }

    return count;
}

// function to find the kth smallest 
// element in a sorted 2D mat
int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // count elements less than or equal to mid
        int count = countSmallerEqual(mat, mid);

        if (count < k) {
            
            // if there are less than k elements
            // <= mid, the kth smallest is larger
            low = mid + 1;
        } else {
            
            // otherwise, mid might be the answer, 
            // but we need to check for smaller values
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = 
                        {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {24, 29, 37, 48},
                        {32, 33, 39, 50 }};
    int k = 3;
    int result = kthSmallest(mat, k);

    cout << result << endl;

    return 0;
}
