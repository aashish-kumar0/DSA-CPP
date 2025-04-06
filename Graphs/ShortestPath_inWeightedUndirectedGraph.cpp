#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>>adj(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto it:edges){
        int node1=it[0];
        int node2=it[1];
        int edgeWeight=it[2];
        adj[node1].push_back({node2,edgeWeight});
        adj[node2].push_back({node1,edgeWeight});
    }
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++)parent[i]=i;
    vector<int>dist(n+1,1e9);
    dist[1]=0;
    pq.push({0,1});
    
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        
        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgeWeight=it.second;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode]=dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode]=node;
            }
        }
    }
    if(dist[n]==1e9){
        return {-1};
    }
    int node=n;
    vector<int>ans;
    while(parent[node]!=node){
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}
    int main() {
        vector<vector<int>> edges = {
            {1, 2, 2},
            {2, 5, 5},
            {2, 3, 4},
            {1, 4, 1},
            {4, 3, 3},
            {3, 5, 1}
        };
        int n=5,m=6;
        vector<int>ans= shortestPath(n,m,edges);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }   
    }