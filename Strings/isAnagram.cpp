#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int>vis(26,0);
        for(int i=0;i<s.size();i++){
            vis[s[i]-'a']++;
            vis[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(vis[i] !=0){
                return false;
            }
        }
        return true;
    }

int main(){
    string s="cat";
    string t="tac";
    if(s==t){
        cout<< "true"<<endl;
    }
    else{
        cout<<"false";
    }
return 0;
}