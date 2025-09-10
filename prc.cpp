#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={3,30,34,5,9};
     string ans="";
        for(int i=0;i<nums.size();i++){
            string curr=to_string(nums[i]);
            ans += curr;
        }
        cout<<ans;
return 0;
}