#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<long long> dist(n, 1e18);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    pq.push({0, 0});
    dist[0] = 0;
    vector<int> ways(n, 0);
    ways[0] = 1;
    int mod = (int)(1e9 + 7);
    while (!pq.empty()) {
        int node = pq.top().second;
        long long time = pq.top().first;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int t = it.second;
            if (time > dist[node])
                continue;

            if (time + t == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }

            else if (time + t < dist[adjNode]) {
                dist[adjNode] = time + t;
                pq.push({time + t, adjNode});
                ways[adjNode] = ways[node];
            }
        }
    }
    return ways[n - 1] % mod;
}

int main(){
return 0;
}