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
node* removeNthFromEndBrute(node* head, int n) {
    if(head==NULL )return NULL;

        int cnt=0;
        node * temp=head;
        while(temp !=NULL){
            cnt++;
            temp=temp->next;
        }
        int res=cnt-n;
        if(cnt ==n){
            node * newHead=head->next;
            delete(head);
            return newHead;
        }
        temp=head;
        while(temp !=NULL){
            res--;
            if(res==0)break;
            temp=temp->next;
        }
        node * delNode=temp->next;
        temp->next=temp->next->next; 
        delete(delNode);
        return head;

    }
    node* removeNthFromEnd(node* head, int n) {
        node * fast=head;
        node * slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){ // for sizeLL=n
            node * newHead=head->next;
            delete(head);
            return newHead;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        node * delNode=slow->next;
        slow->next=slow->next->next;
        delete(delNode);
        return head;
    }
    int main(){

        return 0;
    }