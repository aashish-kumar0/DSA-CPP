#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Memoization
 int f(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(row ==0 && col==0 && obstacleGrid[row][col] != 1) {
        return dp[row][col]=1;
        }
            
        if( row < 0 || col < 0){
            return 0;
        }
        if(obstacleGrid[row][col]==1){
            return dp[row][col]=0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int up= f(row - 1,col, obstacleGrid,dp);
        int left=f(row,col-1,obstacleGrid,dp);

        return dp[row][col]=up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        f(m-1,n-1,obstacleGrid,dp);
        return dp[m-1][n-1];
    }

    // Tabulation
    int uniquePathsWithObstacle(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = 0;
                int left = 0;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } 
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else {
                    
                    if (i > 0) {
                        up = dp[i - 1][j];
                    }
                    if (j > 0) {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    // space optimization
     int uniquePathsWithObstacleS(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = 0;
                int left = 0;
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {

                    up = prev[j];
                    if (j > 0) {
                        left = curr[j - 1];
                    }
                    curr[j] = up + left;
                }
            }
                prev = curr;
        }
        return prev[n - 1];
    }



int main(){
return 0;
}