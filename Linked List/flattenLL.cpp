#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node * merge2List(Node * list1,Node * list2){
        Node * dummy=new Node(-1);
        Node * res=dummy;
        while(list1 != NULL && list2 !=NULL){
            if(list1->data < list2->data){
                res->bottom=list1;
                res=list1;
                list1=list1->bottom;
            }
            else{
                res->bottom=list2;
                res=list2;
                list2=list2->bottom;
            }
            res->next=NULL;
        }
        if(list1 != NULL){
            res->bottom=list1;
        }
        else if(list2 != NULL){
            res->bottom=list2;
        }
        if(dummy->bottom != NULL){
            dummy->bottom->next=nullptr;
        }
        return dummy->bottom;
    }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL){
            return root;
        }
        Node * mergedHead=flatten(root->next);
        root= merge2List(root,mergedHead);
        return root;
    }