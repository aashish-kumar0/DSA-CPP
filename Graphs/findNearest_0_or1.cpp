#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>updateMatrix(vector<vector<int>>& mat){
    int n=mat.size();
    int m= mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> visited(n,vector<int> (m,0));
    int delrow[]={-1,0,0,1};
    int delcol[]={0,-1,1,0};
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){ //for finding nearest 1 
            visited[i][j]=1;
            ans[i][j]=0;
            q.push({{i,j},0});
            }
            else{
                visited[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        ans[r][c]=dis;
        for(int i=0;i<4;i++){
            int nrow=r+ delrow[i];
            int ncol= c+ delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> ans=updateMatrix(mat);
    for(int i=0;i< ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
return 0;
}