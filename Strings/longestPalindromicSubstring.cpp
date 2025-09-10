#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int l;
        int r;
        string ans="";
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            l=i;
            r=i;
            int len=0;
            string temp="";
            // odd length palindrome
            while(l >=0 && r <s.size() && s[l]==s[r]){
                len=r-l+1;
            if(maxlen < len){
                maxlen=max(maxlen,len);
                ans="";
                ans=s.substr(l,len);
            }
                l--;
                r++;
            }

            // even length palindrome
            l=i;
            r=i+1;
            while(l >=0 && r <s.size() && s[l]==s[r]){
                len=r-l+1;
            if(maxlen < len){
                maxlen=max(maxlen,len);
                ans="";
                ans=s.substr(l,len);
            }
                l--;
                r++;
            }
        }
        return ans;
    }

int main(){
return 0;
}