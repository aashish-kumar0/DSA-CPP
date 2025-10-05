#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Memoization
int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target % coins[0] ==0) return target/coins[0] ;
            
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int nottake= 0 + f(ind-1,target,coins,dp);

        int take=INT_MAX;
        if(target >= coins[ind]){
            take= 1 + f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]= min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res = f(n - 1, amount, coins, dp);
        return (res >= 1e9) ? -1 : res;
    }
    // Tabulation
    int coinChangeTabulation(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // base case
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0)dp[0][i]= i/coins[0];
            else dp[0][i]= 1e9;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){

            int nottake= 0 + dp[i-1][target];
            int take=INT_MAX;
            if(target >= coins[i]){
                take= 1 + dp[i][target - coins[i]];
            }
            dp[i][target]=min(take,nottake);
            }
        }
        int res=dp[n-1][amount];
        return (res >= 1e9)? -1 : res;
    }

int main(){
return 0;
}