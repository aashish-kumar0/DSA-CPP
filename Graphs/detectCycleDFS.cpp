#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool detect(vector<vector<int>>& adj, int visited[],int node,int parent){
visited[node]=1;
for(auto it:adj[node]){
    if(!visited[it]){
        if(detect(adj,visited,it,node)==true) return true;
    }
    else if(it != parent){
        return true;
    }
}
return false;
}
bool isCycle(vector<vector<int>> & adj){
int N = adj.size();
int visited[N]={0};
for(int i=0;i<N;i++){
    if(!visited[i]){
        if(detect(adj,visited,i,-1)==true){
            return true;
        }
    }
}
return false;
}
int main(){
    vector<vector<int>>adj = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    cout<<isCycle(adj); 
return 0;
}