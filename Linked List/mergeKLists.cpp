#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};
// Using merge lists approach
class Solution {
    ListNode * merge2Lists(ListNode * l1,ListNode * l2){
        ListNode * dummy=new ListNode(-1);
        ListNode * res=dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                res->next=l1;
                res=res->next;
                l1=l1->next;
            }
            else{
                res->next=l2;
                res=res->next;
                l2=l2->next;
            }
            res->next=NULL;
        }
        if(l1 != NULL){
            res->next=l1;
        }
        else if(l2 != NULL){
            res->next=l2;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        ListNode * head=lists[0];
        for(int i=1;i<k;i++){
            ListNode * temp =lists[i];
            head=merge2Lists(head,temp);
        }
        return head;
    }
};
// using priority queue optimal approach
ListNode* mergeKListsPQ(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < k; i++) {
            ListNode* temp = lists[i];
            if(temp != NULL){
            pq.push({temp->val,temp});
            }
        }
        ListNode * dummy=new ListNode(-1);
        ListNode * temp=dummy;    
        while(! pq.empty()){
            auto p=pq.top();
            pq.pop();
            temp->next=p.second;
            if(p.second->next != NULL){
            pq.push({p.second->next->val,p.second->next});
            }
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
int main(){
return 0;
}