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
node *Insert(node *root, int val)
{
    if (root == NULL)
    {
        root = newNode(val);
    }
    else
    {
        if (root->data > val)
        {
            root->left = Insert(root->left, val);
        }
        else if (root->data < val)
        {
            root->right = Insert(root->right, val);
        }
    }
    return root;
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
node * insertBST(node * root,int val){
    if(root ==NULL){
        root= newNode(val);
    }
    else if(root->data > val){
        root->left=insertBST(root->left,val);
    }
    else if(root->data <=val){
        root->right=insertBST(root->right,val);
    }
    return root;
}

int main(){
return 0;
}