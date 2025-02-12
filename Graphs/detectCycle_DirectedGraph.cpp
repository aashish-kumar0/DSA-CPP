#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis)==true){
                return true;
            }
            else if(pathVis[it]==1){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<vector<int>>&adj){
    vector<int>visited(V,0);
    vector<int>pathVisited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,pathVisited)==true){
                return true;
            }
        }
    }
    return false;
}
int main(){
return 0;
}