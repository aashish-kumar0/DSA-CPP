#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
struct node * newNode(int val){
    node * temp= (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void createTree(node * root,vector<int> vec){
     root->left = newNode(vec[1]);
    root->right = newNode(vec[2]);
    root->left->left = newNode(vec[3]);
    root->left->right = newNode(vec[4]);
    root->right->left = newNode(vec[5]);
    root->right->right = newNode(vec[6]);
}
vector<int> preOrder(node* root,vector<int> &vs){
    if(root==NULL){
        return vs;
    }
    stack<node*> st;
    st.push(root);
    
    while(!st.empty()){
          node* temp=st.top();
        st.pop();
        vs.push_back(temp->data);
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }

    }
    return vs;
}
vector<int> inOrder(node * root,vector<int> & vs){
    if(root==NULL)return vs;
    
}
int main(){
    vector<int>v={1,2,3,4,5,6,7};
    vector<int> ans;
    struct node* root;
    root=newNode(v[0]);
    createTree(root,v);
    preOrder(root,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}