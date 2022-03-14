#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Time Complexcity O(n)
void sumReplacement(node* root){
    if(root==NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left)
        root->data += root->left->data;
    if(root->right)
        root->data += root->right->data;
}

void preOrder(node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
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
    preOrder(root);
    cout<<"\n";
    sumReplacement(root);
    preOrder(root);
    cout<<"\n";
    return 0; 
}