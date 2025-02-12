#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;
    for(auto it:graph[node]){
        if(!vis[it]){
            if(dfs(it,graph,vis,pathVis,check)==true){
                check[node]=0;
                return true;
            }
        }
        else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}

vector<int>eventualSafeNodes(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int>visited(n,0);
    vector<int>pathVisited(n,0);
    vector<int>check(n,0);
    vector<int>safeNode;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,graph,visited,pathVisited,check);
        }
    }
    for(int i=0;i<n;i++){
        if(check[i]==1){
            safeNode.push_back(i);
        }
    }
    return safeNode;
}

int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int>ans=eventualSafeNodes(graph);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}