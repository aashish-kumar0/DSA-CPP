#include <iostream>
#include <bits/stdc++.h>
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
node *Insert(node *root, int val)
{
    if (root == NULL)
    {
        root = newNode(val);
    }
    else{
        if(root->data < val){
            root->left=Insert(root->left,val);
        }
        else if(root->data > val){
            root->right=Insert(root->right,val);
        }
    }
    return root;
}
void preOrder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node * root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node * root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}
node * searchBST(node * root,int key){
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        return searchBST(root->left,key);
    }
    else{
        return searchBST(root->right,key);
    }
}
int main()
{
    node * root=newNode(2);
    root->left=Insert(root->left,1);
    root->right=Insert(root->right,3);
    inOrder(root);

    return 0;
}