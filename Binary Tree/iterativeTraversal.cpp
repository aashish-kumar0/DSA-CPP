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
vector<int>preOrderTraversal( node* root){
    vector<int>preOrder;
    if(root==NULL){
        return preOrder;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node * temp=st.top();
        st.pop();
        preOrder.push_back(temp->data);
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
    return preOrder;
}
vector<int>inOrderTraversal(struct node* root){
    vector<int>inOrder;
    stack<node*>s;
    node* temp=root;
    while(!s.empty() || temp!=nullptr){
    while(temp!=nullptr){
    s.push(temp);
    temp=temp->left;
    }
    temp=s.top();
    s.pop();
    inOrder.push_back(temp->data);
    temp=temp->right;
    }
    return inOrder;
    
}
vector<int> postOrderTraversal(node* root){
    vector<int>postOrder;
    if(root==NULL){
        return postOrder;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node*temp=st.top();
        st.pop();
        postOrder.push_back(temp->data);
        if(temp->left!=NULL){
            st.push(temp->left);
        }
        if(temp->right!=NULL){
            st.push(temp->right);
        }
    }
    reverse(postOrder.begin(),postOrder.end()); //reverse the array
    return postOrder;
}
void createTree(struct node* root){
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

}
int main(){
    node * root= new node(1);
    createTree(root);
    vector<int>ans=inOrderTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}
