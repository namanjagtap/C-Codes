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

void insertionAtTail(node* &head, int val){
	node* n = new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = n;
}

void insertionAtHead(node* &head, int val){
	node* n = new node(val);
	n->next=head;
	head=n;
}

void deleteAtHead(node* &head){
	node* todelete = head;
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
	if(head->data==val || head->next==NULL){
		deleteAtHead(head);
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

int search(node* &head, int val){
	node* temp = head;
	int count = 1;
	while(temp->data!=val){
		count++;
		temp=temp->next;
	}
	return count;
}

void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

node* reverse(node* head){
	node* prevPtr = NULL;
	node* currPtr = head;
	node* nextPtr;

	while(currPtr!=NULL){
		nextPtr=currPtr->next;
		currPtr->next=prevPtr;

		prevPtr=currPtr;
		currPtr=nextPtr;
	}
	return prevPtr;
}

node* reverseK(node* head, int k){
	node* prev = NULL;
	node* curr = head;
	node* nextptr;
	int count=0;
	while(curr!=NULL && count<k){
		nextptr=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextptr;
		count++;
	}
	if(nextptr!=NULL){
		head->next=reverseK(nextptr, k);
	}

	return prev;
}

// Floyd's Algorithm
void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }

        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool cycleDetection(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
     }
     return false;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (fast!=slow);

    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL; 
}

node* merge(node* &head1, node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummynode = new node(-1);
    node* ptr3 = dummynode;

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
        return dummynode->next;
}

node* mergeRecursive(node* &head1, node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next=mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next=mergeRecursive(head1, head2->next);
    }
    return result;
}

void evenafterodd(node* &head){
    node* even = head->next;
    node* odd = head;
    node* evenstart = even;

    while( odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next=evenstart;

    if(odd->next!=NULL){
        even->next=NULL;
    }
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insertionAtTail(head1, 1);
    insertionAtTail(head2, 2);
    insertionAtTail(head1, 3);
    insertionAtTail(head2, 4);
    insertionAtTail(head2, 5);
    insertionAtHead(head1, 0);
    // makeCycle(head, 3);
    // cout<<cycleDetection(head)<<endl;
    // removeCycle(head);
    // cout<<cycleDetection(head)<<endl;
    // display(head);
    // cout<<search(head, 7)<<endl;
    // deleteAtHead(head);
    // int k=3;
    // node* newHead=reverse(head);
    // display(newHead);
    node* newhead = mergeRecursive(head1, head2);
    display(newhead);
    evenafterodd(newhead);
    display(newhead);
    return 0;
}