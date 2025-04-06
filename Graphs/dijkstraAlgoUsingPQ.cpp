#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int>dist(adj.size(),1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int node = pq.top().second;
        int dis=pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgeWeight= it.second;
            if(dis+ edgeWeight < dist[adjNode]){
                dist[adjNode]=dis+ edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main(){
return 0;
}