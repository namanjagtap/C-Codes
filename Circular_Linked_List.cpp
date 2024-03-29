#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        n->next=n;
        head= n;
        return;
        
    }
    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void dispaly(node* head){
    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp!=head);
    cout<<endl;
}

void deleteAtHead(node* &head){
    node* temp = head;
    while (temp->next!=head){
        temp=temp->next;
    }
    node* todelete = head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}

void deleteByPos(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count!=pos-1){
        temp=temp->next;

        count++;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

void deleteByVal(node* &head, int val){
    if(head==NULL){
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    dispaly(head);
    insertAtHead(head, 0);
    dispaly(head);
    deleteByPos(head, 4);
    dispaly(head);
    deleteAtHead(head);
    dispaly(head);


    return 0;
}