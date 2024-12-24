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
void inOrder(node * root,int &counter,int k,int &result){
    if(root==NULL){
        return;
    }
    inOrder(root->left,counter,k,result);
    counter++;
    if(counter==k){
        result=root->data;
        return;
    }
    inOrder(root->right,counter,k,result);
}
int kthSmallest(node * root,int k){
    int Smallest=-1;
    int counter=0;
    inOrder(root,counter,k,Smallest);
    return Smallest;
}
int main(){

return 0;
}