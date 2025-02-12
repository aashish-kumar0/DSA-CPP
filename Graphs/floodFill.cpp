#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &ans,
         vector<vector<int>> &image, int newColor, int delrow[],
         int delcol[], int iniColor)
{
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    if (iniColor == newColor)
        return;
    q.push({row, col});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != newColor)
            {
                ans[row][col] = newColor;
                q.push({nrow, ncol});
            }
        }
    }
}

void dfs(int row, int col, vector<vector<int>> &ans,
         vector<vector<int>> &image, int newColor, int delrow[],
         int delcol[], int iniColor)
{
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    for (int i = 0; i < 4; i++)
    {
        int neighRow = row + delrow[i];
        int neighCol = col + delcol[i];
        if (neighRow >= 0 && neighRow < n && neighCol >= 0 &&
            neighCol < m && image[neighRow][neighCol] == iniColor &&
            ans[neighRow][neighCol] != newColor)
        {
            dfs(neighRow, neighCol, ans, image, newColor, delrow, delcol,
                iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    bfs(sr, sc, ans, image, color, delrow, delcol, iniColor);
    return ans;
}
int main()
{

    return 0;
}