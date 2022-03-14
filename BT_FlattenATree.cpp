#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void flatten(node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    if(root->left!=NULL){
        flatten(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node* t = root->right;
        while(t->right!=NULL)
            t=t->right;
        t->right=temp;
    }
    flatten(root->right);
}

void inOrder(node* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->left->left = new node(5);
    root->left->left->right = new node(6);
    root->left->right->right = new node(7);
    root->left->left->left->left = new node(8);
    inOrder(root);
    cout<<"\n";
    flatten(root);
    inOrder(root);
    return 0;
}
/*
                    1
                   /
                  2
                 / \
                3   4
               / \   \
              5   6   7
             /
            8
*/