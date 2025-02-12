#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,int delrow[],int delcol[]){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row + delrow[i];
            int ncol=col + delcol[i];
            if(nrow>=0 && nrow<n&& ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,visited,delrow,delcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        int count=0;
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,visited,delrow,delcol);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid,visited,delrow,delcol);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[j][0]==1){
                dfs(j,0,grid,visited,delrow,delcol);
            }
            if(grid[j][m-1]==1){
                dfs(j,m-1,grid,visited,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
int main(){
    vector<vector<int>> grid = {
    {0, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
cout<<numEnclaves(grid);
return 0;
}