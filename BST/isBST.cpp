#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *newNode(int val)
{
    node *root = (node *)malloc(sizeof(node));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}
bool isBST(node * root,long minVal,long maxVal){
    if(root==NULL){
        return true;
    }
    if(root->data < minVal || root->data > maxVal){
        return false;
    }
    return isBST(root->left,minVal,root->data)&& isBST(root->right,root->data,maxVal);
}
bool isValidBST(node * root){
    return isBST(root,LONG_MIN,LONG_MAX);
}
int main(){
    
    return 0;
}