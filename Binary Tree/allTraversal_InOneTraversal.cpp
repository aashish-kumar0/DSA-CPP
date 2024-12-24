#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(){}
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void createTree(node* root){
        root->left=new node(2);
        root->right=new node(5);
        root->left->left=new node(3);
        root->left->right=new node(4);
        root->right->left=new node(6);
        root->right->right=new node(7);
}
void preInPostTraversals(node* root,vector<int> &preOrder,vector<int>&inOrder,vector<int>&postOrder){
        stack<pair<node*,int>>st;
        st.push({root,1});
        if(root==NULL){
            return;
        }
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            // this is part of preOrder
            // increment 1 to 2
            //push the left side of the tree
            if(it.second==1){
                preOrder.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->left!=NULL){
                    st.push({it.first->left,1});
                }
            }
            //this is a part of inOrder
            else if(it.second==2){
                inOrder.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->right!=NULL){
                    st.push({it.first->right,1});
                }
            }
            else{
                postOrder.push_back(it.first->data);
            }
        }
}
int main(){
    node * root= new node(1);
    createTree(root);
    vector<int>pre,in,post;
    preInPostTraversals(root,pre,in,post);
    cout<<"PreOrder traversal\n";
    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    cout<<"In Order Traversal\n";
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    cout<<"Post Order Traversal\n";
    for(int i=0;i<post.size();i++){
        cout<<post[i]<<" ";
    }
return 0;
}