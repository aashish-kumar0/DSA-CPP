#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string temp=strs[0];
        string ans;
        for(int i=1;i<strs.size();i++){
            string s=strs[i];
            ans="";
            int j=0;
            while(j < temp.size() && j < s.size() && temp[j]==s[j] ){
                ans.push_back(temp[j]);
                j++;
            }
            temp=ans;
        }
        return ans;
    }

int main(){
    vector<string>s={"flower","flow","flight"};
    cout<<longestCommonPrefix(s)<<endl;
return 0;
}