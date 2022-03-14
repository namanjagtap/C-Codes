#include <iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;

    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

int height(node* root){
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(rh, lh) + 1;
}

//Time Complexity O(n^2)
bool isBalanced(node* root){
    if(root==NULL)
        return true;
    if(isBalanced(root->left)==false)
        return false;
    if(isBalanced(root->right)==false)
         return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

//Time Complexity O(n)
bool isBalanced(node* root, int* height){
    if(root==NULL){
        return true;
    }
    int lh=0, rh=0;
    if(isBalanced(root->left, &lh)==false)
        return false;
    if(isBalanced(root->right, &rh)==false)
        return false;
    *height = max(rh, lh) + 1;
    if(abs(lh - rh) <=1)
        return true;
    else
        return false;
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
    int height = 0;
    isBalanced(root) ? cout<<"Balanced"<<endl : cout<<"Not balanced"<<endl;
    isBalanced(root, &height) ? cout<<"Balanced"<<endl : cout<<"Not balanced"<<endl;
    return 0; 
}