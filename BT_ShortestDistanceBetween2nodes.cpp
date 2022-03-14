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


node* LCA(node* root, int n1, int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    
    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);

    if(left && right)
        return root;
    if(left==NULL && right==NULL)
        return NULL;
    if(left)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int findDis(node* root, int k, int dis){
    if(root==NULL)
        return -1;
    if(root->data==k)
        return dis;
    
    int left = findDis(root->left, k, dis+1);
    if(left!=-1)
        return left;
    int right = findDis(root->right, k, dis+1);
}

int disBtwNodes(node* root, int n1, int n2){
    node* lca = LCA(root, n1, n2);

    int d1 = findDis(lca, n1, 0);
    int d2 = findDis(lca, n2, 0);

    return (d1 + d2);
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
    cout<<disBtwNodes(root, 6, 4)<<endl;
    return 0;
}