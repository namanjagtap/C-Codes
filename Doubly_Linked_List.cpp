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

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    
    n->next=head;
    if(head!=NULL){
        head->previous=n;
    }
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
        temp->next=n;
        n->previous=temp;
}

void display(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->NULL"<<endl;
    cout<<"Back traversal"<<endl;
    while(temp!=head){
        cout<<temp->data<<"->";
        temp=temp->previous;
    }
    cout<<temp->data<<"->NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->previous=NULL;

    delete todelete;
    cout<<"deleteAtHead executed."<<endl;
}

void deleteNode(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count=1;
    while(temp->next!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    node* todelete = temp;
    temp->previous->next=temp->next;
    if(temp->next!=NULL){
        temp->next->previous=temp->previous;
    }

    delete todelete;
    cout<<"deleteNode executed."<<endl;
}
// Append last k nodes in Linked List
int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* kappend(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail=head;

    int l = length(head);
    cout<<l<<endl; 
    k=k%l;
    int count=1;

    if(k==0)
        return head;
    
    if(k==1){
        node* temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node* newTail = temp;
        node* newHead = temp->next;
        temp->next->next=head;
        newTail->next=NULL;
        return newHead;
    }

    while(tail->next!=NULL){
        if(count==l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    head->previous=tail;

    return newhead;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d=0;
    node* prt1;
    node* prt2;

    if(l1>l2){
        d=l1-l2;
        prt1=head1;
        prt2=head2;
    }
    else{
        d=l2-l1;
        prt1=head2;
        prt2=head1;
    }
    while(d){
        prt1=prt1->next;
        if(prt1==NULL){
            return -1;
        }
        d--;
    }
    while(prt1 != NULL && prt2 != NULL){
        if(prt1==prt2){
            return prt1->data;
        }
        prt1=prt1->next;
        prt2=prt2->next;
    }
    return -1;
}

node* merge(node* &head1, node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummyNode=new node(-1); 
    node* ptr3=dummyNode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
        
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummyNode->next;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 6);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);
    insertAtTail(head2, 3);
    insertAtTail(head2, 5);
    insertAtTail(head2, 10);
    // insertAtHead(head, 0);
    // intersect(head1, head2, 3);
    display(head1);
    // display(head2);
    // cout<<intersection(head1, head2)<<endl;
    // deleteNode(head, 1);
    node* newhead=kappend(head1, 2);
    display(newhead);
    // node* newhead= merge(head1,head2);
    // display(newhead);
    return 0;
}