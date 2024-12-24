#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,int vis[],vector<int>&ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}
vector<int>DfsOfGraph(vector<vector<int>>& adj){
    int visited[adj.size()]={0};
    int start=1;  //for node starting from 1
    vector<int>list;
    dfs(start,adj,visited,list);
    return list;
}
int main(){
    vector<vector<int>>adj={{0},{2,3},{1,5,6},{1,4,7},{3,8},{2},{2},{3,8},{4,7}};
    vector<int>ans=DfsOfGraph(adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}