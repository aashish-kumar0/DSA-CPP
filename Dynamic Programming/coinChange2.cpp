#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Memoization
 int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target % coins[0] ==0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake= 0 + f(ind-1,target,coins,dp);
        int take=0;
        if(target >= coins[ind]){
            take= f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]= take + nottake;
    }
    // tabulation

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount + 1,0));

        // base case
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0) dp[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){

                int nottake=0 + dp[i-1][target] % INT_MAX;

                int take=0;
                if(target >= coins[i]){
                    take= dp[i][target-coins[i]] % INT_MAX;
                }
                dp[i][target]=(take + nottake) % INT_MAX;
            }
        }

        return dp[n-1][amount] % INT_MAX;
    }

int main(){
return 0;
}