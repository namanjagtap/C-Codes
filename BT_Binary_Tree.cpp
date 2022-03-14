#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    public:
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->left->left->left = new node(8);
	root->left->left->right = new node(9);
	root->left->right->left = new node(10);
	root->left->right->right = new node(11);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    return 0; 
}

/*
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
*/