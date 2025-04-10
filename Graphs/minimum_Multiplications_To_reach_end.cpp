#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr,
    int start, int end) {
vector<int>dist(100000,1e9);
dist[start]=0;
queue<pair<int,int>>q;
q.push({0,start});

while(!q.empty()){
int steps=q.front().first;
int node=q.front().second;
q.pop();

for(int i=0;i<arr.size();i++){
int num=(node * arr[i]) % 100000;
if(dist[num] > steps +1){
if(num == end){
return steps + 1;
}
q.push({steps + 1,num});
dist[num]=steps + 1;
}
}
}
return -1;
}

int main(){
return 0;
}