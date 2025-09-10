#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// memoization
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return dp[i][j] = grid[i][j];
    }
    if (i < 0 || j < 0)
        return INT_MAX;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = f(i - 1, j, grid, dp);
    int left = f(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left) + grid[i][j];
}
// tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = INT_MAX;
            int left = INT_MAX;
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {

                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            int up;
            int left;
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
            }
            else
            {
                up = prev[j];
                if (j > 0)
                {
                    left = curr[j - 1];
                }
                curr[j] = min(up, left) + grid[i][j];
            }
        }
        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    return 0;
}