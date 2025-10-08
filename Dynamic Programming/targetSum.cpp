#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==0){
            if(nums[0]==0 && target==0) return 2;
            if(nums[0]==target || target==0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake= f(ind-1,target,nums,dp);

        int take= 0;
        if(target >= nums[ind]){
            take= f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]= take + nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int S=0;
        for(int i=0;i<n;i++) S+= nums[i];
    
        if(S-target >=0 && (S-target)%2==0){
            int s2= (S-target)/2;
            vector<vector<int>>dp(n,vector<int>(s2+1,-1));
            return f(n-1,s2,nums,dp);
        }
        return 0;
    }

};
int main(){
return 0;
}