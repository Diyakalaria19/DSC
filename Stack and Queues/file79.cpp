
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// function to perform bfs and find minimum time
int orangesRot(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // queue to store coordinates of rotten oranges
    queue<pair<int, int>> q;

    // counter of elapsed time
    int elapsedTime = 0;

    // push all initially rotten oranges into queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    // directions for all four adjacent cells
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // perform BFS
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false; 

        // process all oranges at current time level
        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;

            q.pop();

            // check all four directions
            for (auto dir : directions)
            {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // if cell is safe and has fresh orange
                if (isSafe(nx, ny, n, m) && mat[nx][ny] == 1)
                {
                    // rot the orange
                    mat[nx][ny] = 2;
                    q.push({nx, ny});
                    flag = true;
                }
            }
        }

        // if at least one orange got rotten, increase the time
        if (flag)
            elapsedTime++;
    }

    // check if any fresh orange still remains
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                return -1;
        }
    }

    return elapsedTime;
}

int main()
{
    vector<vector<int>> mat = {{2, 1, 0, 2, 1},
                               {1, 0, 1, 2, 1},
                               {1, 0, 0, 2, 1}};
    cout << orangesRot(mat);
    return 0;
}
