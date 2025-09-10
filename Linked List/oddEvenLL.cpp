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

node * createLL(node * head,vector<int>&arr){
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i]);
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}
void traversalLL(node * head){
node * ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}


 node* oddEvenList(node* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        node * odd=head;
        node * even=head->next;
        node * evenHead=head->next;
        while(even != NULL && even->next !=NULL ){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }


int main(){
    vector <int> arr={1,4,9,6,85};
    node * head=new node(arr[0]);
    createLL(head,arr);
    traversalLL(head);
return 0;
}