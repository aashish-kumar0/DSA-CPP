#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector <int> arr){
    int maxi=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
        }
    }
    return maxi;
}
int main(){
vector<int> a={1,1,1,0,1,1,1,1,0,1,1};
int ans=maxConsecutiveOnes(a);
cout<<ans;
return 0;
}