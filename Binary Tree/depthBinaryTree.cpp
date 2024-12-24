#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node*right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void createTree(node * root){
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(6);
    root->right->left->left=new node(5);
}
int depthBinaryTree(node * root){
    if(root==NULL){
        return 0; 
    }
    int lh=depthBinaryTree(root->left);
    int rh=depthBinaryTree(root->right);
    return 1+max(lh,rh);
}
int main(){
    node * root= new node(1);
    createTree(root);
    int depth=depthBinaryTree(root);
    cout<<depth<<endl;
return 0;
}