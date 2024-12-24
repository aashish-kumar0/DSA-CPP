#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// OPTIMAL APPROACH>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
vector <int> intersectionArray(vector <int> &a,vector <int> &b){
     int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i]>b[j]){
            i++;
        }
        else if(a[i]<b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

// brute approach>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
vector <int> intersectionArr(vector <int> a,vector <int> b){
    int n=a.size();
    int m=b.size();
    int visited[m]={0};
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]&& visited[j]==0){
                ans.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if(b[j>a[i]]){
                break;
            }
        }
    }
    return ans;
}
int main(){
    vector<int>A={1,2,2,3,3,4,5,6};
    vector<int>B={2,3,3,5,6,6,7};
    int n,m;
    vector<int>temp=intersectionArray(A,B);
    for(int i=0;i<5;i++){
        cout<<temp[i]<<" ";
    }

return 0;
}