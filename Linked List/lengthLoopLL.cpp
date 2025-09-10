#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

// Function to find the length of a loop in the linked list.
    int countNodesinLoopBrute(Node *head) { // using map data structure
        // Code here
        if(head==NULL || head->next==NULL){
            return 0;
        }
        unordered_map<Node *,int>mpp;
        int t=1;
        Node * temp=head;
        while(temp != NULL){
            if(mpp.find(temp)!=mpp.end()){
                int value=mpp[temp];
                return t-value;
            }
            mpp[temp]=t;
            t++;
            temp=temp->next;
        }
        return 0;
    }
    // optimal approach(tortoise & hare algo)
    int findLen(Node * slow,Node * fast){
        int cnt=1;
        fast=fast->next;
        while(slow != fast){
            cnt++;
            fast=fast->next;
        }
        return cnt;
    }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(head== NULL || head->next == NULL)return 0;
        Node * slow=head;
        Node * fast=head;
        while(fast !=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return findLen(slow,fast);
            }
            
        }
        return 0;
    }
    int main(){

        return 0;
    }