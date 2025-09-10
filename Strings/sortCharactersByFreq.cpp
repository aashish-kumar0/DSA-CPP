#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char,int>mpp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<vector<char>> bucket(s.size()+1);
        
        for(auto it: mpp){
            bucket[it.second].push_back(it.first);
        }

       for (int i = bucket.size() - 1; i > 0; --i) {
        for (char ch : bucket[i]) {
            ans += string(i, ch);
        }
    }
        return ans;
    }

int main(){
return 0;
}