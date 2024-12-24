#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
vector<int>topView(node * root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<pair<node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node * temp=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()){
            mpp[line]=temp->data;
        }
        if(temp->left!=NULL){
            q.push({temp->left,line-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,line+1});
        }
    }
    for(auto p:mpp){
        ans.push_back(p.second);
    }
    return ans;
}
int main(){
return 0;
}