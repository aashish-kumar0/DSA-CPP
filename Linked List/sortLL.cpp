 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct  ListNode {
    int val;
    ListNode * next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};
// using bubble sort algo
 ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        int cnt = 1;
        while (temp->next != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for (int i = 0; i < cnt; i++) {
            temp = dummy->next;
            ListNode* prev = dummy;
            while (temp->next != NULL) {
                ListNode* front = temp->next;
                if (temp->val > front->val) {
                    temp->next = front->next;
                    front->next = temp;
                    prev->next = front;
                    prev = prev->next;
                } else {
                    temp = temp->next;
                    prev = prev->next;
                }
            }
        }
        return dummy->next;
    }
    // merge sort
    class Solution {
    ListNode * findMiddle(ListNode * head){
        ListNode * slow=head;
        ListNode * fast=head->next;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (temp1 != NULL || temp2 != NULL) {
            if (temp1 != NULL && temp2 != NULL) {
                if (temp1->val <= temp2->val) {
                    ListNode* newNode = new ListNode(temp1->val);
                    curr->next = newNode;
                    curr = newNode;
                    temp1 = temp1->next;
                } else {
                    ListNode* newNode = new ListNode(temp2->val);
                    curr->next = newNode;
                    curr = newNode;
                    temp2 = temp2->next;
                }
            } else if (temp1 != NULL) {
                ListNode* newNode = new ListNode(temp1->val);
                curr->next = newNode;
                curr = newNode;
                temp1 = temp1->next;
            } else if (temp2 != NULL) {
                ListNode* newNode = new ListNode(temp2->val);
                curr->next = newNode;
                curr = newNode;
                temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * middle=findMiddle(head);
        ListNode * lefthead=head;
        ListNode * righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        head=mergeTwoLists(lefthead,righthead);
        return head;
    }
};