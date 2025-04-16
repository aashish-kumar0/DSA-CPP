#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
return 0;
}




class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>> cities(n, vector<int>(n, INT_MAX));
            for (auto it : edges) {
                cities[it[0]][it[1]]=it[2];
                cities[it[1]][it[0]]=it[2];
            }
            for (int i = 0; i < n; i++) {
                cities[i][i] = 0;
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (cities[i][k] == INT_MAX || cities[k][j] == INT_MAX) {
                            continue;
                        }
                        cities[i][j] =
                            min(cities[i][j], cities[i][k] + cities[k][j]);
                    }
                }
            }
            int cntCity=n;
            int cityNo=-1;
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                    if(cities[i][j]<= distanceThreshold){
                        count++;
                    }
                }
                if(count <= cntCity){
                    cntCity=count;
                    cityNo=i;
                }
            }
            return cityNo;
        }
    };