#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&adj,vector<int>&visited,int start){
    visited[start]=1;
    vector<int>bfs;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }

}
void dfs(vector<vector<int>> & adjList,int node,vector<int>&vis){
    vis[node]=1;
    //visit all unvisited neighbours
    for(int i=0;i<adjList.size();i++){
        if(adjList[node][i]==1 && !vis[i]){
            dfs(adjList,i,vis); // or bfs()
        }
    }
}
int countProvinces(vector<vector<int>> & adjList){
    int n=adjList.size();
    vector<int>visited(n,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(adjList,i,visited);
        }
    }
    return count;
}
int main(){
    vector<vector<int>>adj = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<countProvinces(adj);
return 0;
}