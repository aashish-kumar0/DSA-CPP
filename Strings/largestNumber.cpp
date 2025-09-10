#include<iostream>
#include<bits/stdc++.h>
using namespace std;


static bool myComparater(string a ,string b){
        string t1= a+b;
        string t2= b+a;
        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {

        vector<string>s;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        
        sort(s.begin(),s.end(),myComparater);

        if(s[0]=="0"){
            return "0";
        }

        string ans="";
        for(int i=0;i<s.size();i++){
            ans += s[i];
        }
        return ans;
    }

int main(){
return 0;
}