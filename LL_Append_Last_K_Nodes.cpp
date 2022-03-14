#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;

    node(int val){
        data=val;
        next=NULL;
        previous=NULL;
    }
};

int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

void kappend(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail=head;

    int l = length(head);
    int count=1;
    while(tail->next!=NULL){
        if(count=l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
}