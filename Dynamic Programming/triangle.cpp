#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int below=f(row+1,col,triangle,dp);
        int right= f(row+1,col+1,triangle,dp);

        return dp[row][col]=  min(below,right) + triangle[row][col];
 }
 // tabulation
  int minimumTotal(vector<vector<int>>& triangle) {
         int m=triangle.size();
         vector<vector<int>>dp(m,vector<int>(m,-1));
         // base case
         for(int j=0;j<m;j++){
             dp[m-1][j]=triangle[m-1][j];
         }

         for(int i=m-2;i>=0;i--){
             for(int j=i;j>=0;j--){


                 int down= dp[i+1][j];
                 int diag= dp[i+1][j+1];

                 dp[i][j]=min(down,diag) + triangle[i][j];
             }
         }
         return dp[0][0];
     }
     // space optimization
     int minimumTotalS(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>prev(m,0);
        // base case
        for(int j=0;j<m;j++){
            prev[j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            vector<int>curr(m,0);
            for(int j=i;j>=0;j--){

                int down= prev[j] + triangle[i][j];
                int diag= prev[j+1] + triangle[i][j];

                curr[j]=min(down,diag) ;
            }
            prev=curr;
        }
        return prev[0];
    }


int main(){
    vector<vector<int>>triangle ={{1},{2,3},{3,6,7},{8,9,6,10}};
    cout<<minimumTotal(triangle);
return 0;
}