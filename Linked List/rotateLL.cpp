#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

         ListNode * temp=head;
         ListNode * tail=head;
         int len=1;
         while(tail->next != NULL){
            len++;
            tail=tail->next;
         }
         int n=k % len;
         if( k % len ==0){
            return head;
         }
         else {
            for(int i=0;i<(len-n-1);i++){
                temp=temp->next;
            }
            tail->next=head;
            head=temp->next;
            temp->next=NULL;

         }
         return head;

    }