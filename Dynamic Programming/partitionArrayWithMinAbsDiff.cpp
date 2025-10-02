#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    vector<vector<bool>>f(int s,vector<int>& nums){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(s+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;

        if(s >= nums[0]){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int t=1;t<=s;t++){

                bool nottake=dp[i-1][t];

                bool take=false;
                if(t >= nums[i]){
                    take=dp[i-1][t-nums[i]];
                }
                dp[i][t]= take || nottake;
            }
        }
        return dp;
    }

    int minimumDifference(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        for(int i=0;i<n;i++) s+=nums[i];
        vector<vector<bool>>dp=f(s,nums);

        int mini=1e9;
        for(int i=0;i<=s;i++){
            if(dp[n-1][i] == true){
                int s1=i;
                int s2=s-i;
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }





int main(){
    vector<int>nums={3,9,7,3};
    cout<<minimumDifference(nums);
return 0;
}