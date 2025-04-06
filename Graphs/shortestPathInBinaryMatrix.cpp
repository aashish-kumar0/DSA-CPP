#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    if(grid[0][0]!=0){ // starts from 1
        return -1;
    }
    if(grid[n-1][n-1] !=0){
        return -1;
    }
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    dist[0][0]=0;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{0,0}});
    
    while(!q.empty()){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        if(row== n-1 && col == n-1){
            return dis +1 ;
        }
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nrow=row + i;
                int ncol= col+ j;
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol]==0){
                    if(dis  + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
    }
    return -1;
}


int main(){
return 0;
}