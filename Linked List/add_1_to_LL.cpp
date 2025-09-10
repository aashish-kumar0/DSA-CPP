#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node (int data1){
        data=data1;
        next=NULL;
    }
};

Node * reverseLL(Node * head){
        if(head==NULL || head->next ==NULL)return head;
        Node * newHead=reverseLL(head->next);
        Node * front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    Node* addOneBrute(Node* head) {
        // Your Code here
        if(head==NULL)return NULL;
        int carry=1;
        head=reverseLL(head);
        Node * temp=head;
        Node * prev=NULL;
        while(temp !=NULL){
            int sum=temp->data + carry;
            temp->data=sum % 10;
            carry=sum/10;
            prev=temp;
            temp=temp->next;
        }
        if(carry >0){
            prev->next=new Node(carry);
        }
        head=reverseLL(head);
        return head;
    }
    // optimal approach
     int helper(Node * temp){
        if(temp ==NULL){
            return 1;
        }
        int carry=helper(temp->next);
        int sum=temp->data + carry;
        temp->data=sum % 10;
        carry=sum / 10;
        return carry;
    }
    Node* addOne(Node* head) {
        int carry=helper(head);
        if(carry > 0){
            Node * newNode = new Node(carry);
            newNode->next=head;
            return newNode;
        }
        return head;
        
    }
int main(){
return 0;
}