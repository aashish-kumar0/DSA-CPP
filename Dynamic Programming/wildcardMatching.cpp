#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    // memoization
    bool f(int i, int j, string s, string p,vector<vector<int>>&dp) {
        // base case
        if (i < 0 && j < 0)
            return true;
        if ( j < 0 && i >= 0)
            return false;

        if(i < 0 && j >=0){
            for(int ii=0;ii<=j;ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j]=='?')
            return dp[i][j]= f(i - 1, j - 1, s, p,dp);

            if (p[j] == '*')
                return dp[i][j]= f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);

            return dp[i][j]= false;
        }

public:
// Tabulation
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));

        dp[0][0]=true;

        for(int i=1;i<=n;i++) dp[i][0]= false;

        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int jj=1; jj<=j; jj++){
                if(p[jj-1] != '*'){
                    flag=false;
                    break;
                }

            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]= dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
       
    }
};


int main(){
    Solution s;
    string s1="abdefcd";
    string p="ab*cd";
    bool ans=s.isMatch(s1,p);
    cout<<ans;
return 0;
}