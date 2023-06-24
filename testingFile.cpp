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

void insertAtTail(node* &head, int val){
	node* n = new node(val);
	if(head == NULL){
		head = n;
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
	if(head == NULL){
		head = n;
		return;
	}
	n->next = head;
	head = n;
}

void deleteAtHead(node* &head){
	if(head == NULL){
		return;
	}
	node* todelete = head;
	head = head->next;
	delete todelete;
}

void deleteByVal(node* &head, int val){
	if(head==NULL || head->next==NULL || head->data == val){
		deleteAtHead(head);
		return;
	}
	node* temp = head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

void deleteByPos(node* &head, int pos){
	if(head==NULL || pos==1){
		deleteAtHead(head);
		return;
	}
	int count = 1;
	node* temp = head;
	while(temp->next!=NULL && count!=pos-1){
		temp = temp->next;
		count++;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

node* reverse(node* &head){
	node* prevNode = NULL;
	node* currNode = head;
	node* nextNode;

	while(currNode!=NULL){
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	return prevNode;
}

node* reverseRecursive(node* &head){
	if(head==NULL || head->next==NULL)
		return head;
	node* newHead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

node* reverseK(node* &head, int k){
	node* prevNode = NULL;
	node* currNode = head;
	node* nextNode;
	int count = 0;
	while(currNode!=NULL && count!=k){
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
		count++;
	}
	if(nextNode!=NULL){
		head->next = reverseK(nextNode, k);
	}
	return prevNode;
}

void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void makeCycle(node* &head, int k){
	node* temp = head;
	node* startNode;
	int count = 0;

	while(temp->next!=NULL){
		if(count==k)
			startNode = temp;
		temp=temp->next;
		count++;
	}
	temp->next = startNode;
}

bool detectCycle(node* &head){
	node* fast = head;
	node* slow = head;

	while(fast->next!=NULL && fast!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}

void removeCycle(node* &head){
	node* fast = head;
	node* slow = head;

	do
	{
		fast=fast->next->next;
		slow=slow->next;
	} while (fast!=slow);
	fast = head;

	while(fast->next!=slow->next){
		fast=fast->next;
		slow=slow->next;
	}
	slow->next=NULL;
}

int main(){
	node* head = NULL;
	insertAtHead(head, 0);
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	// deleteAtHead(head);
	display(head);
	makeCycle(head, 4);
	cout<<boolalpha<<detectCycle(head)<<endl;
	removeCycle(head);
	cout<<boolalpha<<detectCycle(head)<<endl;
	return 0;
}