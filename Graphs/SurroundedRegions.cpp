#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int row,
             int col,int delrow[],int delcol[]) {
                int n = board.size();
        int m = board[0].size();
                visited[row][col]=1;
                
                for(int i=0;i<4;i++){
                    int nrow= row+ delrow[i];
                    int ncol= col+ delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                        dfs(board,visited,nrow,ncol,delrow,delcol);
                    }
                }
             }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[]={-1,0,0,1};
                int delcol[]={0,-1,1,0};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(board,visited,0,i,delrow,delcol);
            }
            if (board[n - 1][i] == 'O' && !visited[n-1][i]) {
                dfs(board,visited,n-1,i,delrow,delcol);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[j][0] == 'O' && !visited[j][0]) {
                dfs(board,visited,j,0,delrow,delcol);
            }
            if (board[j][m - 1] == 'O' && !visited[j][m-1]) {
                dfs(board,visited,j,m-1,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    solve(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
return 0;
}