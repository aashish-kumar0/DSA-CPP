#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data1){
        data=data1;
        next=nullptr;
    }
    node(int x,node * ptr){
        data=x;
        next=ptr;
    }
};
node* middleNodeBrute(node* head) {
        if(head==NULL ||head->next ==NULL){
            return head;
        }
        node * temp=head;
        int cnt=0;
        while(temp !=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
            int mid= (cnt/2) + 1;
        while(temp != NULL){
            mid--;
            if(mid==0){
                break;
            }
            temp=temp->next;
        }
        return temp;
    }
    // tortoise hare algo
    node* middleNode(node* head) {
        if(head== NULL || head->next == NULL){
            return head;
        }
        node * fast=head;
        node * slow=head;
        while(fast != NULL && fast->next !=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
int main(){
return 0;
}