//Distance of nearest cell having 1 in a binary matrix
#include <iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

    // to store the indices of the cells having 1
    queue<pair<int, int>> q;

    // visit each cell of the grid
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {

            // if the cell has 1, 
            // then the distance is 0
            if(grid[i][j] == 1) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // iterate over all the cells
    // and find the distance of the nearest 1
    while(!q.empty()) {
        int len = q.size();
        
        for(int i = 0; i<len; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // check all the four directions
            vector<vector<int>> directions = 
            {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (int j = 0; j < directions.size(); j++) {
                int dx = directions[j][0];
                int dy = directions[j][1];

                // if the cell is within the grid 
                // and the distance is not calculated yet
                if (x+dx >= 0 && x+dx < n && y+dy >= 0 && 
                    y+dy < m && ans[x+dx][y+dy] == INT_MAX) {
                    ans[x+dx][y+dy] = ans[x][y] + 1;
                    q.push({x+dx, y+dy});
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {{0,1,1,0}, {1,1,0,0}, {0,0,1,1}};
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}