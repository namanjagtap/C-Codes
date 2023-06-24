#include <iostream>
using namespace std;

class node{
    public:
        node* next;
        int data;
    
    node(int val){
        next = NULL;
        data = val;
    }
};

void insertIntoTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        // insertAtHead(head, val);
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    n->next = head;
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}

void deleteByPos(node* &head, int pos){
    if(head==NULL)
        return;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count != pos-1){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void deleteByVal(node* &head, int val){
    node* n = new node(val);
    if(head->data==val){
        deleteAtHead(head);
        return;
    }
    if(head==NULL)
        return;
    node* temp = head;
    while(temp->next->data!=val)
        temp=temp->next;
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

bool search(node* &head, int val){
    node* temp = head;
    int count = 1;
    while(temp->data!=val){
        count++;
        temp=temp->next;
    }
    if(temp->data==val)
        cout<<"Element found at "<<count<<endl;
    else
        cout<<"Element not found"<<endl;
}

node* reverse(node* &head){
    node* currPtr = head;
    node* prevPtr = NULL;
    node* nextPtr;
        
    while(currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL)
        return head;
    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(){
    node* head = NULL;
    insertIntoTail(head, 1);
    insertIntoTail(head, 2);
    insertIntoTail(head, 3);
    insertIntoTail(head, 4);
    insertAtHead(head, 0);
    display(head);
    node* newHead = reverseRecursive(head);
    display(newHead);

    return 0;
}