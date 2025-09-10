#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
      int data;
      Node *next;
      Node * prev;
      Node(int x) : data(x), next(NULL),prev(NULL) {}
  };

void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node * back=NULL;
        Node * temp=*head_ref;
        Node * front=temp;
        while(temp !=NULL){
            if(temp->data==x){
                if(temp == *(head_ref)){
                    *head_ref=(*head_ref)->next;
                }
                front=temp->next;
                back=temp->prev;
                if(front != NULL){
                    front->prev=back;
                }
                if(back != NULL){
                    back->next=front;
                }
                Node * delNode=temp;
                delete(delNode);
                temp=temp->next;;
                
            }
            else{
            temp=temp->next;
            }
        }
    }
int main(){
return 0;
}