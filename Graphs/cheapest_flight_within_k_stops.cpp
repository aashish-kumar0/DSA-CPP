#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    vector<int>cost(n,1e9);
    cost[src]=0;
    while(!q.empty()){
    int steps=q.front().first;
    int node=q.front().second.first;
    int price=q.front().second.second;
    q.pop();
    for(auto it:adj[node]){
        int adjNode=it.first;
        int c=it.second;
        if(steps >k)continue;
        if(steps <= k && price + c < cost[adjNode] ){
            q.push({steps+1,{adjNode,c + price}});
            cost[adjNode]=c + price;
        }
    } 
    }
    if(cost[dst]==1e9)return -1;
    return cost[dst];

}

int main(){
return 0;
}