#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
};
void createTree(node *root, vector<int> &vec)
{
    root->left = newNode(vec[1]);
    root->right = newNode(vec[2]);
    root->left->left = newNode(vec[3]);
    root->left->right = newNode(vec[4]);
    root->right->left = newNode(vec[5]);
    root->right->right = newNode(vec[6]);
}
void createTree(node *root, vector<int> &vec)
{
    root->left = newNode(vec[1]);
    root->right = newNode(vec[2]);
    root->left->left = newNode(vec[3]);
    root->left->right = newNode(vec[4]);
    root->right->left = newNode(vec[5]);
    root->right->right = newNode(vec[6]);
}
void inOrderTraversal(struct node *temp, vector<int> &inorder)
{
    if (temp == NULL)
    {
        return;
    }
    inOrderTraversal(temp->left, inorder);
    inorder.push_back(temp->data);
    inOrderTraversal(temp->right, inorder);
}
void preOrderTraversal(struct node *temp, vector<int> &preOrder)
{
    if (temp == NULL)
        return;
    preOrder.push_back(temp->data);
    preOrderTraversal(temp->left, preOrder);
    preOrderTraversal(temp->right, preOrder);
}
void postOrderTraversal(struct node* temp,vector<int>postOrder){
    if(temp==NULL)return ;
    postOrderTraversal(temp->left,postOrder);
    postOrderTraversal(temp->right,postOrder);
    postOrder.push_back(temp->data);
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    struct node *root0 = newNode(v[0]);
    createTree(root0, v);
    cout<<"In-Order Traversal"<<endl;
    vector<int> inOrder;
    inOrderTraversal(root0, inOrder);
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout << " " << inOrder[i];
    }
    cout<<endl;
    cout<<"Pre-Order Traversal"<<endl;
    vector<int> preOrder;
    preOrderTraversal(root0, preOrder);
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << " " << preOrder[i];
    }
    return 0;
}