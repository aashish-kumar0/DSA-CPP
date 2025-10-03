#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// memoization
class SolutionMemoization {
    int f(int ind,int target,vector<int>& arr,vector<vector<int>>&dp){
        // base case
        if(ind==0){
            if (target==0 && arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake= f(ind-1,target,arr,dp);
        int take= 0;
        if(target >= arr[ind]){
            take=f(ind-1,target-arr[ind],arr,dp);
        }
        return  dp[ind][target] =take + nottake;
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++) sum += arr[i];
        int s2= (sum-d)/2;
        
        if(sum-d >=0 && (sum-d)%2==0){
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return f(n-1,s2,arr,dp);
        }
        
        return 0;
    }
};
// tabulation
int perfectSum(vector<int>& arr, int target) {

        int n=arr.size();
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
                dp[i][t]=take + nottake;
            }
        }
        
        return dp[n-1][target];
    }
    int countPartition(vector<int>& arr, int d) {
        // Code here
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++) sum += arr[i];
        int s2= (sum-d)/2;
        
        if(sum-d >=0 && (sum-d)%2==0){
        return perfectSum(arr,s2);
        }
        
        return 0;
    }

int main(){
return 0;
}