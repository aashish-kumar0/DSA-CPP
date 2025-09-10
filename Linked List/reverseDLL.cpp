#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
int data;
class node * next;
class node * back;
node(int x,node * y,node *z){
    data=x;
    next=y;
    back=z;
}
node(int data1){
    data=data1;
    next=nullptr;
    back=nullptr;
}
};

node * createLL(vector<int>&arr){
    node * head=new node(arr[0]);
    node * prev=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}
void traversal(node * head){
    node * ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

 node* reverseDLLNaive(node* head) { // naive solution
        // Your code here
        if(head==NULL){
            return nullptr;
        }
        node * temp=head;
        stack<int>st;
        while(temp!=NULL){
            st.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->data=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
    //optimal solution
    node* reverseDLL(node* head) {
        // Your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        node * current =head;
        node * last=nullptr;
        while(current !=NULL){
            last=current->back;
            current->back=current->next;
            current->next=last;
            current=current->back;
        }
        
        return last->back;
    }

int main(){
return 0;
}