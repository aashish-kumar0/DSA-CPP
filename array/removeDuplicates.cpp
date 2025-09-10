#include<bits/stdc++.h>
using namespace std;
int removeDuplicate(vector<int>&arr,int n){
    int i=0;
     n=arr.size();
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    vector<int>arr={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicate(arr,arr.size());
    return 0;
}