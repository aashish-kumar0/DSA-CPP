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
// brute appproach using map data structure
bool hasCycleBrute(node *head) { 
        if(head==NULL || head->next==NULL){
            return false;
        }
        node * temp=head;
        unordered_map<node*,int>mpp;
        while(temp!=NULL){
            if(mpp.find(temp) !=mpp.end()){
                return true;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;
    }
    // optimal approach(tortoise and hare algo)
    bool hasCycle(node *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        node * fast=head;
        node * slow=head;
        while(fast != NULL && fast->next !=NULL) {
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
int main(){
return 0;
}