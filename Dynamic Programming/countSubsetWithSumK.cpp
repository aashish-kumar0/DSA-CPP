#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursive approach
int f(int ind, vector<int> &arr, int target)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // include and exclude
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }

    int nottake = f(ind - 1, arr, target);

    int take = 0;
    if (target >= arr[ind])
    {

        take = f(ind - 1, arr, target - arr[ind]);
    }

    return take + nottake;
}

// Memoization
int fn(int ind,vector<int>& arr, int target,vector<vector<int>>&dp){
        if(ind == 0) {
            if(target == 0 && arr[0] == 0) return 2; // include and exclude
            if(target == 0 || arr[0] == target) return 1;
                return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int nottake= fn(ind-1,arr,target,dp);
        
        int take= 0;
        if(target >= arr[ind]){
            
        take =fn(ind-1,arr,target-arr[ind],dp);
        }
        
        return dp[ind][target]= take + nottake;
    
    }
    // Tabulation
    int findWays(vector<int>& arr, int target)
{
	 int n=arr.size();
     int mod=1e9 + 7;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        // base case
        if (arr[0] == 0) {
        dp[0][0] = 2; // {} and {0}
        } else {
        dp[0][0] = 1; // only {}
        if (arr[0] <= target)
            dp[0][arr[0]] = 1; // {arr[0]}
    }
        if(target==0 && arr[0]==0){
            dp[0][arr[0]]=2;
        }
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                
                int nottake= dp[i-1][t];
                
                int take=0;
                if(t >= arr[i]){
                    take= dp[i-1][t-arr[i]];
                }
                dp[i][t]=(take + nottake) % mod;
            }
        }
        
        return dp[n-1][target];

}

int main()
{
    return 0;
}