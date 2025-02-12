#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool detectCycle(vector<vector<int>> & adj,int start, int visited[]){
    visited[start]=1;
    queue<pair<int,int>>q;
    q.push({start,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent= q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> & adj){
    int n=adj.size();
    int visited[n]={0};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectCycle(adj,i,visited)==true){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>>adj = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    cout<<isCycle(adj); 
return 0;
}