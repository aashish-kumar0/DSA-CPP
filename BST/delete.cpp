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
node * findLastRight(node * root){
    if(root==NULL){
        return root;
    }
    return findLastRight(root->right);
}
node * helper(node * root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    else{
        node * rightChild=root->right;
        node * lastRight= findLastRight(root->left);
        lastRight->right=rightChild;
        return root->left;
    }
}
node * deleteNode(node *root, int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        return helper(root);
    }
    node * temp=root;
    while(root!=NULL){
    if(root->data > val){
        if(root->left!=NULL && root->left->data==val){
            root->left=helper(root->left);
            break;
        }
        else{
            root=root->left;
        }
    }
    else{
        if(root->right!=NULL && root->right->data==val){
            root->right=helper(root->right);
            break;
        }
        else{
            root=root->right;
        }
    }
    }
    return temp;
}
int main(){
return 0;
}