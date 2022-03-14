#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	node(int val){
		data = val;
		left=NULL;
		right=NULL;
	}
};

int search(int inOrder[], int start, int end, int curr){
	for(int i=start;i<=end;i++){
		if(inOrder[i]==curr)
			return i;
	}
	return -1;
}

node* buildTree(int inOrder[], int preOrder[], int start, int end){
	static int idx = 0;
	if(start>end)
		return NULL;
	int curr = preOrder[idx];
	idx++;
	node* root = new node(curr);
	if(start==end)
		return root;
	int pos = search(inOrder, start, end, curr);
	root->left=buildTree(inOrder, preOrder, start, pos-1);
	root->right=buildTree(inOrder, preOrder, pos+1, end);
	return root;
}

void display(struct node* root){
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

int main(){
	int inorder[]={4, 2, 1, 5, 3};
	int preOrder[]={1, 2, 4, 3 ,5};
	node* root = buildTree(inorder, preOrder, 0, 4);
	display(root);

	return 0;
}