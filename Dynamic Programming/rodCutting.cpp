#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// memoization
 int f(int ind,int len,vector<int> &price,vector<vector<int>>&dp)
    {
        if(ind==0){
            return dp[0][len]= price[0] * len;
        }
        if(dp[ind][len] != -1) return dp[ind][len];
        
        int nottake= 0 + f(ind-1,len,price,dp);
        
        int take=0;
        if(len >= ind+1){
         take= price[ind]+ f(ind,len- (ind + 1) ,price,dp);
        }
        
        return dp[ind][len]= max(take,nottake);
        
    }

// tabulation
int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        // index x length is the config. of dp array
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        // base case
        for(int i=1;i<=n;i++) dp[0][i]= price[0] * i;
        
        for(int i=1;i<n;i++){
            for(int len=1;len<=n;len++){
                
                int nottake= 0 + dp[i-1][len];
                
                int take=0;
                if(len >= (i+1)){
                    take= price[i] + dp[i][len-(i+1)];
                }
                dp[i][len]= max(take,nottake);
            }
        }
        
        return dp[n-1][n];
    }

int main(){
return 0;
}