#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int>dist(adj.size(),1e9);
    set<pair<int,int>>st;
    dist[src]=0;
    st.insert({0,src});
    while(!st.empty()){
        auto it = *(st.begin());
        int node=it.second;
        int dis=it.first;
        st.erase(it);

        for(auto a:adj[node]){
            int adjNode=a.first;
            int edgeWeight=a.second;
            if(dis+ edgeWeight < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=dis + edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}    

int main(){
return 0;
}