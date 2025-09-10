#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode * next;
    ListNode(int data1){
        data=data1;
        next=nullptr;
    }
    ListNode(int x,ListNode * ptr){
        data=x;
        next=ptr;
    }
};

// tortoise & hare algo
ListNode* deleteMiddle(ListNode* head) {
        if(head ==NULL || head->next == NULL){
            return NULL;
        }
        ListNode * slow=head;
        ListNode * fast=head;
        ListNode * prev=NULL;
        while(fast != NULL && fast->next != NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        // free(slow);
        return head;;
    }
int main(){
return 0;
}