#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// memoization approach
bool f(int ind, int target,vector<int>& arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0 ) return (arr[0]==target);
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool nottake= f(ind-1,target,arr,dp);
        
        bool take= false;
        if(target >= arr[ind]){
            take=f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]= (nottake || take);
    }


// tabulation approach
  bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
        // for any index if target==0 then return true
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        // if ind==0 and target ==arr[0] return true
        dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                
                bool nottake= dp[i-1][target];
                
                bool take=false;
                if(target >= arr[i]){
                    take=dp[i-1][target-arr[i]];
                }
                
                dp[i][target]= (take || nottake);
            }
        }
        return dp[n-1][sum];
    }
    // space optimization 

int main(){
return 0;
}