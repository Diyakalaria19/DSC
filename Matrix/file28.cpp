
//Rotate matrix by 90 degrees
#include <bits/stdc++.h>
using namespace std;

// Function to rotate a square matrix by 90 degrees
// in clockwise direction
void rotate90(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
  	// Reverse Columns
    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
        
    // Perform Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }    

}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    rotate90(mat);

    // Print the rotated matrix
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
