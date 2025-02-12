#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(int start,vector<vector<int>>&graph,vector<int> &colored){
    int n=graph.size();
    colored[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: graph[node]){
            if(!colored[it]){
                colored[it]= !colored[node];
                q.push(it);
            }
            else if(colored[it]==colored[node]){
                return false;
            }
        }
    }
    return true;
}
bool bipariteGraph(vector<vector<int>> & graph){
    int n=graph.size();
    vector<int> colored(n,-1);
    for(int i=0;i<n;i++){
        if(colored[i]==-1){
            if(check(i,graph,colored)==false){
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>>graph = {{1,3},{0,2},{1,3},{0,2}};
    bool ans=bipariteGraph(graph);
    cout<<ans;
return 0;
}