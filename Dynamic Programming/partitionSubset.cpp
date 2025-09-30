#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
return 0;
}


bool canPartition(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        for(int i=0;i<n;i++) s += nums[i];
        if(s%2 != 0) return false;

        vector<bool>prev(s/2+1,0);
        vector<bool>curr(s/2+1,0);
        
        prev[0]=true;
        if(s/2 >= nums[0]){
        prev[nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int t=1;t<= s/2;t++){
                bool nottake= curr[t];

                bool take=false;
                if(t >= nums[i]){
                    take= prev[t- nums[i]];
                }
                curr[t]= take || nottake;
            }
            prev=curr;
        }
        return prev[s/2];
    }