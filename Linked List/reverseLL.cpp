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

// iterative appproach
node* reverseListIterative(node* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        node * prev=nullptr;
        node * curr=head;
        while(curr !=NULL){
            node * nextTemp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextTemp;
        }
        return prev;
    }
    node* reverseList(node* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        node * newHead=reverseList(head->next);
        node * front=head->next;

        front->next=head;
        head->next=NULL;
        return newHead;
    }
    int main(){

        return 0;
    }