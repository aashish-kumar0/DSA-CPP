#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind,vector<int>&nums,vector<int>&dp){
    if(ind == 0){
        return nums[0];
    }
    if(ind < 0) return 0;
    if(dp[ind] != -1)return dp[ind];
    int pick= nums[ind];
        pick += f(ind-2,nums,dp);

    int notpick= 0 + f(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}

// tabular approach
int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);

        vector<int> temp1(nums.begin(), nums.end() - 1); // 0 to n-2
        vector<int> temp2(nums.begin() + 1, nums.end()); // 1 to n-1
        dp1[0]=temp1[0];
        for(int i=1;i<temp1.size();i++){
            int pick=temp1[i];
            if(i > 1){
                pick += dp1[i-2];
            }
            int notpick= 0 + dp1[i-1];
            dp1[i]=max(pick,notpick);
        }
        dp2[0]=temp2[0];
        for(int i=1;i<temp2.size();i++){
            int pick=temp2[i];
            if(i > 1){
                pick += dp2[i-2];
            }
            int notpick= 0 + dp2[i-1];
            dp2[i]=max(pick,notpick);
        }
        return max(dp1[temp1.size()-1],dp2[temp2.size()-1]);
    }

    // space optimised approach
    int fn(vector<int>&nums){
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take= nums[i];
            if(i > 1) take += prev2;
            int notpick=0 + prev1;
            
            int curr=max(take,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int mainF(vector<int>&nums){
        vector<int>temp1(nums.begin(),nums.end()-1);
        vector<int>temp2(nums.begin()+1,nums.end());
         return max(fn(temp1),fn(temp2));
    }

int main(){
return 0;
}