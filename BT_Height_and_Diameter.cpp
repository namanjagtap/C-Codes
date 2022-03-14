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

int height(node* root){
    if(root==NULL)
        return 0;
    int lftHgt = height(root->left);
    int rgtHgt = height(root->right);
    return max(lftHgt, rgtHgt)+1;
}

//Time Complexity O(n)
int diameterEfficiently(node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = diameterEfficiently(root->left, &lh);
    int RDiameter = diameterEfficiently(root->right, &rh);
    
    int currDiameter = lh  + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, RDiameter));
}

//Time Complexity O(n^2)
int diameter(node* root){
    if(root==NULL)
        return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiameter = lHeight+rHeight+1;

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
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
    cout<<diameterEfficiently(root, &height)<<endl;
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