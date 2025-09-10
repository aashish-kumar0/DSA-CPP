#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(int ind,vector<int>&arr,int n,vector<int>& nums,vector<vector<int>> & ans){
        if(ind >= n){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        helper(ind+ 1,arr,n,nums,ans);
        arr.pop_back();
        helper(ind + 1,arr,n,nums,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp={};
        int n=nums.size();
        helper(0,temp,n,nums,ans);
        return ans;
    }

int main(){
return 0;
}