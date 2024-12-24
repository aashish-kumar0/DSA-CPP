#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
vector<vector<int>>verticalOrder(node * root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        node * temp=p.first;
        int x= p.second.first;
        int y=p.second.first;
        nodes[x][y].insert(temp->data);
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p: nodes){
        vector<int>col;
        for(auto r: p.second){
            col.insert(col.end(),r.second.begin(),r.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
return 0;
}