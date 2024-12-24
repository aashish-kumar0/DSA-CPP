#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string optimalSum(vector <int> arr,int target){
    // array must be sorted
    sort(arr.begin(),arr.end());
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        if(arr[left]+arr[right]<target){
            left++;
        }
        else if(arr[left]+arr[right]>target){
            right--;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}
 vector<int> betterSum(vector <int> arr,int target){
    map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        int a=arr[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()){
            return {mpp[more],i};
        }
     
        mpp[a]=i;

    }
        return {-1,-1};
}
void bruteSum(vector <int> arr,int target){
    for(int i=0;i<arr.size();i++){
        int a=arr[i];
        for(int j=i;j<arr.size();j++){
            if(a+arr[j]==target){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
 
int main(){
    vector<int> ar={2,6,5,8,11};
    int target=14;
    vector<int> b=betterSum(ar,target);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
return 0;
}