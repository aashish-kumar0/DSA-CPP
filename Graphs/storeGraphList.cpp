// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>adj[n+1];   //array of vectors
//     for(int i=0;i<m;i++){
//         int u,v;  // u & v are node and neighbor respectively
//         //u<---->v  (undirected graphs)
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
// return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to create and return the adjacency list
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Step 1: Initialize adjacency list with empty lists for each vertex
    vector<vector<int>> adjList(V);
    
    // Step 2: Process each edge using a simple for loop
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        // Add v to the adjacency list of u and u to the adjacency list of v
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // Step 3: Sort adjacency lists for consistent output (optional)
    for (int i = 0; i < V; ++i) {
        sort(adjList[i].begin(), adjList[i].end());
    }
    
    return adjList;
}

int main() {
    int V = 5, E = 7;
    vector<pair<int, int>> edges = {{0,1}, {0,4}, {4,1}, {4,3}, {1,3}, {1,2}, {3,2}};
    
    // Create the adjacency list
    vector<vector<int>> adjList = printGraph(V, edges);
    
    // Output the adjacency list
    for (int i = 0; i < V; ++i) {
        cout << "[";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j];
            if (j != adjList[i].size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
