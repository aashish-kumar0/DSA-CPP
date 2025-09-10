#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        int r=0;
        while(r < s.size()){
            if(s != goal){
                string t=s.substr(0,1);
                s.push_back(s[0]);
                s.erase(0,1);
            }
            else {
                return true;
            }
                r++;
        }
        return false;
    }

int main(){
return 0;
}