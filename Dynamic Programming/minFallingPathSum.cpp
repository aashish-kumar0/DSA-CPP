#include<bits/stdc++.h>
using namespace std;

int f(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(row < 0 || col < 0 || col >= matrix[0].size()) return 1e9;
        if(row==matrix.size()-1){
            return dp[row][col]=matrix[row][col];
        }
        if(dp[row][col] !=-1){
            return dp[row][col];
        }

        int leftdiag=f(row+1,col-1,matrix,dp) + matrix[row][col];
        int down= f(row+1,col,matrix,dp) + matrix[row][col];
        int rightdiag= f(row+1,col+1,matrix,dp) + matrix[row][col];
        return dp[row][col]= min(leftdiag,min(down,rightdiag));
    }
    // tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
            int mini=INT_MAX;
            int n=matrix.size();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            // base case
            for(int i=0;i<n;i++){
                dp[0][i]=matrix[0][i];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int ldiag= INT_MAX;
                    if(i-1 >=0 && j-1>=0){
                        ldiag = matrix[i][j]+ dp[i-1][j-1];
                    }
                    int up= matrix[i][j] + dp[i-1][j];
                    int rdiag= INT_MAX;
                    if(j + 1 < n){
                        rdiag = matrix[i][j] + dp[i-1][j+1];
                    }
                    dp[i][j]= min(ldiag,min(up,rdiag));
                }
            }
            for(int i=0;i<n;i++){
                int curr=dp[n-1][i];
                if(mini > curr){
                    mini=curr;
                }
            }
            return mini;
        }
        // space optimization
         int minFallingPathSums(vector<vector<int>>& matrix) {
                int mini=INT_MAX;
                int n=matrix.size();
                vector<int>prev(n,0);
                // base case
                for(int i=0;i<n;i++){
                    prev[i]=matrix[0][i];
                }

                for(int i=1;i<n;i++){
                    vector<int>temp(n,0);
                    for(int j=0;j<n;j++){
                        int ldiag= INT_MAX;
                        if(i-1 >=0 && j-1>=0){
                            ldiag = matrix[i][j]+ prev[j-1];
                        }
                        int up= matrix[i][j] + prev[j];
                        int rdiag= INT_MAX;
                        if(j + 1 < n){
                            rdiag = matrix[i][j] + prev[j+1];
                        }
                        temp[j]= min(ldiag,min(up,rdiag));
                    }
                    prev=temp;
                }
                for(int i=0;i<n;i++){
                    int curr=prev[i];
                    if(mini > curr){
                        mini=curr;
                    }
                }
                return mini;
            }

int main(){

return 0;
}