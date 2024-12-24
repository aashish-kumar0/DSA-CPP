#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>bfsGraph(vector<vector<int>> & adj){
    vector<int>bfs;
    int visited[adj.size()]={0};
    visited[0]=1; //for node starting from 0
    //visited[1]=1;  ->> for node starting from 1
    queue<int>q;
    q.push(0);
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
    return bfs;
}
int main(){
    vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
    vector<int>ans=bfsGraph(adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}