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

node * deletingHead(node * head){
    if(head==NULL){
        return head;
    }
    else if(head->next==NULL && head->back==NULL){
        free(head);
        return NULL;
    }
    node * ptr=head;
    head=head->next;
    head->back=nullptr;
    ptr->next=nullptr;
    free(ptr);
    return head;
}

node * deletingTail(node * head){
if(head==NULL){
        return head;
    }
    else if(head->next==NULL && head->back==NULL){
        free(head);
        return NULL;
    }
    node * ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next->back=nullptr;
    free(ptr->next);
    ptr->next=nullptr;
    return head;
    
}

node * deletingK(node * head,int k){
    if(head==NULL)return head;
    node * ptr=head;
    int cnt=0;
    while(ptr!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        ptr=ptr->next;
    }
    node * prev=ptr->back;
    node * front=ptr->next;
    if(prev==NULL && front==NULL){ // only one node
        free(ptr);
        return head;
    }
    else if(prev==NULL){ // standing at head
        head=front;
        free(ptr);
        return head;
    }
    else if(front==NULL){ // standing at tail
        prev->next=nullptr;
        ptr->back=nullptr;
        free(ptr);
        return head;
    }
    else{
        prev->next=front;
        front->back=prev;
        ptr->back=nullptr;
        ptr->next=nullptr;
        free(ptr);
        return head;
    }
}

//insertion

node * insertHead(node * head,int val){
if(head==NULL){
    head->data=val;
    return head;
}
node * temp=new node(val);
head->back=temp;
temp->next=head;
head=temp;
return head;
}

// insert at tail
node * insertTail(node * head,int val){
    if(head==NULL){
    head->data=val;
    return head;
}
node * temp=new node(val);
node * ptr=head;
while(ptr->next!=NULL){
    ptr=ptr->next;
}
ptr->next=temp;
temp->back=ptr;
return head;
}

// insert at kth index
node* insertAtK(node* head, int k, int val) {
    node* newNode = new node(val);

    if (k <= 1 || head == nullptr) {
        // Insert at head
        newNode->next = head;
        if (head != nullptr) head->back = newNode;
        return newNode;
    }

    node* ptr = head;
    int count = 1;

    // Traverse to (k-1)th node or last node if k > length
    while (ptr->next != nullptr && count < k - 1) {
        ptr = ptr->next;
        count++;
    }

    node* front = ptr->next;
    ptr->next = newNode;
    newNode->back = ptr;

    newNode->next = front;
    if (front != nullptr) {
        front->back = newNode;
    }

    return head;
}


int main(){
    vector<int>arr={7,5,98,24,19};
    node * head=createLL(arr);
    deletingTail(head);
    traversal(head);

    return 0;
}