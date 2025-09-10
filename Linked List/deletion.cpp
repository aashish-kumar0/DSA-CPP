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
// deletion of head
node * deleteHead(node * head){
    if(head==nullptr)return head;
    node * ptr=head;
    head=head->next;
    delete(ptr);
    return head;
}
// deletion of tail
node * deleteTail(node * head){
    if(head==NULL || head->next==NULL)return NULL;
    node * ptr=head;
    while(ptr->next->next!=nullptr){
        ptr=ptr->next;
    }
    free(ptr->next->next);
    ptr->next=NULL;
    return head;
}
// deleting Kth element
node * deleteK(node * head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    node * ptr=head;
    node * prev=NULL;
    while(ptr!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(ptr);
            break;
        }
        ptr=ptr->next;
    }
    return head;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    node * head=new node(arr[0]);
    createLL(head,arr);
    traversalLL(head);
    cout<<"\n";
    head=deleteTail(head);
    traversalLL(head);

return 0;
}