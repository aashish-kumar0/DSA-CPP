#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
struct node * newNode(int val){
    node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
vector<vector<int>>levelOrder(node * root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
        auto it=q.front();
        q.pop();
        level.push_back(it->data);
        if(it->left!=NULL){
            q.push(it->left);
        }
        if(it->right!=NULL){
            q.push(it->right);
        }
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
return 0;
}