#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Memoization
int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp){
        // base case
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        // if matches
        if(text1[ind1]==text2[ind2]) 
        return dp[ind1][ind2]= 1 + f(ind1-1,ind2-1,text1,text2,dp);

        // if not matches
        return dp[ind1][ind2]= 0 + max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }
    // Tabulation
     int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
int main(){
return 0;
}