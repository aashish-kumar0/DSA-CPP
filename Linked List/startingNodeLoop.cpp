#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  ListNode *detectCycleBrute(ListNode *head) { // brute approach
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode * temp=head;
        unordered_map<ListNode *,int>mpp;
        while(temp !=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    }
    // optimal approach(tortoise and hare algorithm)
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast !=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow != fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
int main(){
return 0;
}