#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    for(int delrow=-1; delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int neighrow= row+ delrow;
                int neighcol= col+ delcol;
                if(neighrow >=0 && neighrow < n && delcol >=0 && delcol <m && grid[neighrow][neighcol]=='1' && !vis[neighrow][neighcol]){
                    dfs(grid,vis,neighrow,neighcol);
                }
            }
        }
}
void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //traverse all its neighbors
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int neighrow=row+delrow;
                    int neighcol=col+ delcol;
                    if(neighrow >=0 && neighrow <n && neighcol>=0 && neighcol<m && grid[neighrow][neighcol]=='1' && !vis[neighrow][neighcol]){
                        vis[neighrow][neighcol]=1;
                            q.push({neighrow,neighcol});
                    }
                }
            }
        }
    }
    // Main Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
int main(){
    vector<vector<char>>grid = {{0,1},{1,0},{1,1},{1,0}};
    cout<<numIslands(grid);
return 0;
}