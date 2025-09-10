#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
int data;
class node * next;
node(int x,node * y){
    data=x;
    next=y;
}
node(int data1){
    data=data1;
    next=nullptr;
}
};

node * createLL(node * head,vector<int>&arr){
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i]);
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}
void traversalLL(node * head){
node * ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

// insertion at head
node * insertAtHead(node * head,int val){
    if(head==NULL){
        head->data=val;
        return head;
    }
    node * ptr=new node(val);
    ptr->next=head;
    head=ptr;
    return head;
}

node * insertAtTail(node * head,int val){
    if(head==NULL){
        head->data=val;
        return head;
    }
    node * ptr=new node(val);
    node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    return head;
}

node * insertK(node * head,int val,int k){
    if(head==NULL){
        head->data=val;
        return head;
    }
    if(k==1){
        node * ptr = new node(val);
        ptr->next=head;
        head=ptr;
        return head;
    }
    node * ptr=new node(val);
    int count=0;
    node * temp=head;
    while(temp!=NULL){
        count++;
        if(count==k){
            
        }
    }
}

int main(){
    vector <int> arr={1,4,9,6,85};
    node * head=new node(arr[0]);
    createLL(head,arr);
    traversalLL(head);
    cout<<"\n";
    head=insertAtHead(head,56);
    traversalLL(head);
return 0;
}