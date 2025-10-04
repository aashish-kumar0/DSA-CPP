#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// memoization
int f(int ind,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp)
    {
        // Base Case
        if(ind==0)
        {
            if(W >= wt[0]){
                return val[0];
            }
            else return 0;
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int nottake= 0 + f(ind-1,W,val,wt,dp);
        
        int take=INT_MIN;
        if(wt[ind] <= W){
            take = val[ind] + f(ind-1,W-wt[ind],val,wt,dp);
        }
        return   dp[ind][W]= max(take,nottake);
    }

    // tabulation
    int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
	//  int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
        
        for(int i=1;i<n;i++){
            for(int Wt=1;Wt<=W;Wt++){
                
                int nottake= 0 + dp[i-1][Wt];
                
                int take= INT_MIN;
                if(wt[i] <= Wt){
                    take= val[i] + dp[i-1][Wt-wt[i]];
                }
                
                dp[i][Wt]= max(take,nottake);
            }
        }
        
        return dp[n-1][W];
}
// space optimization

    int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
	//  int n=val.size();
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        
        for(int i=wt[0];i<=W;i++) prev[i]=val[0];
        
        for(int i=1;i<n;i++){
            for(int Wt=1;Wt<=W;Wt++){
                
                int nottake= 0 + prev[Wt];
                
                int take= INT_MIN;
                if(wt[i] <= Wt){
                    take= val[i] + prev[Wt-wt[i]];
                }
                
                curr[Wt]= max(take,nottake);
            }
            prev=curr;
        }
        
        return prev[W];
}
int main(){
return 0;
}