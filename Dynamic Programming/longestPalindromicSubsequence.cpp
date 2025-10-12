#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string &s,string &s1){
        int n=s.size();
        int m=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s1[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j]= 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalinSubseq(string &s) {
        // code here
        string s1=s;
        reverse(s1.begin(),s1.end());
        return lcs(s,s1);
    }
int main(){
return 0;
}