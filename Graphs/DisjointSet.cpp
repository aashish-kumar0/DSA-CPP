#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
vector<int>rank,parent,size;
public:
DisjointSet(int n){
    // 1-based indexing
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}
int findUPar(int node){ // to find ultimate parent
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=findUPar(parent[node]);
}   
void findUnionByRank(int u,int v){
    int ultPar_u=findUPar(u);  //ultimate parent of u
    int ultPar_v=findUPar(v);
    if(ultPar_u==ultPar_v)return;
    if(rank[ultPar_u]<rank[ultPar_v]){
        parent[ultPar_u]=ultPar_v;
    }
    else if(rank[ultPar_v] <  rank[ultPar_u] ){
        parent[ultPar_v]=ultPar_u;
    }
    else{
        parent[ultPar_v]=ultPar_u;
        rank[ultPar_u]++;
    }
}
void findUnionBySize(int u,int v){
    int ultPar_u=findUPar(u);  //ultimate parent of u
    int ultPar_v=findUPar(v);
    if(ultPar_u==ultPar_v)return;
    if(size[ultPar_u]< size[ultPar_v]){
        parent[ultPar_u]=ultPar_v;
        size[ultPar_v]=size[ultPar_v]+size[ultPar_u];
    }
    else{
        parent[ultPar_v]=ultPar_u;
        size[ultPar_u]=size[ultPar_v]+size[ultPar_u];
    }
}
};

int main(){
    DisjointSet ds(7);
    ds.findUnionBySize(1,2);
    ds.findUnionBySize(2,3);
    ds.findUnionBySize(4,5);
    ds.findUnionBySize(6,7);
    ds.findUnionBySize(5,6);
    // check if 3 & 7 belongs to the same component or not
    cout<<"Before: ";
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    ds.findUnionBySize(3,7);
    //after
    cout<<"After : ";
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"not same\n";
    }
return 0;
}