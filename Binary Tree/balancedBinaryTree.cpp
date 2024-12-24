#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(){}
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void createTree(node*root){
    root->left=new node(2);
    root->right=new node(3);
}
int heightBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=heightBinaryTree(root->left);
    int rh=heightBinaryTree(root->right);
    if(lh==-1 || rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return max(lh,rh)+1;
}
int main(){
return 0;
}