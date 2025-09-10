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

node* segregateBrute(node* head) { //brute approach
        // code here
        if(head==NULL || head->next ==NULL){
            return head;
        }
        int cnt0,cnt1,cnt2=0;
        node * temp=head;
        while(temp != NULL){
            if(temp->data ==0)cnt0++;
            if(temp->data ==1)cnt1++;
            if(temp->data ==2)cnt2++;
        }
        temp=head;
        while(temp !=NULL){
            if(cnt0 > 0){
                temp->data=0;
                cnt0--;
            
            }
            else if(cnt1 > 0){
                temp->data=1;
                cnt1--;
                
            }
            else if(cnt2 > 0){
                temp->data=2;
                cnt2--;
            }
                temp=temp->next;
        }
        return head;
    }
     node* segregate(node* head) { // optimised approach
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        node * temp=head;
        node * zeroHead= new node(-1);
        node * oneHead= new node(-1);
        node * twoHead= new node(-1);
        node * zero=zeroHead;
        node * one=oneHead;
        node * two=twoHead;
        while(temp !=NULL){
            if(temp->data ==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else if(temp->data==2){
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next=twoHead->next;
        two->next=nullptr;
        node * newHead=zeroHead->next;
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        return newHead;
    }

int main(){
return 0;
}