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
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int Ceil(node *root, int key)
{
    int ceil = -1;
    if (root == NULL)
    {
        return -1;
    }
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root->data;
        }
        else if (root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}
int floor(node * root,int key){
    int floor=-1;
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
    if(root->data==key)return root->data;
    else if(root->data > key){
        root=root->left;
    }
    else{
        floor=root->data;
        root=root->right;
    }
   }  
   return floor;
}
int main()
{
    node *root =(node *)malloc (sizeof(node));
    root=NULL;
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        root = Insert(root, arr[i]);
    }
    // inOrder(root);
    cout << Ceil(root, 3);
  
    return 0;
}