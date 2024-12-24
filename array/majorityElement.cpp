#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Optimal solution>>>>>MOORE'S VOTING ALGORITHM>>>>>>>>>>>>>>>>>>>>
int optimalMajority(vector<int> arr){
    int count=0;
    int element;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            count=1;
            element=arr[i];
        }
        else if(arr[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==element){
            count1++;
        }
    }
    if(count1>(arr.size()/2)){
        return element;
    }
    return -1;
}
// better solution>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int betterMajority(vector <int> arr,int n){
    map<int,int>mpp;
    n=arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second > (n/2)){
            return it.first; 
        }
    }
    return -1;
}
// brute Soluton
int bruteMajority(vector <int>arr,int n){
    n=arr.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>(n/2)){
            return arr[i];
        }
    }
    return -1;
}
int main(){
    int n;
vector <int> ar={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
int a=optimalMajority(ar);
cout<<a;
return 0;
}