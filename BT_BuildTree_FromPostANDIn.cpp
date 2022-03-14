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

int search(int inOrder[], int start, int end, int curr){
    for(int i=start;i<end;i++){
        if(inOrder[i]==curr)
            return i;
    }
    return -1;
}

node* buildTree(int postOrder[], int inOrder[], int start, int end){
    static int idx = end;
    if(start>end)
        return NULL;
    int curr = postOrder[idx];
    idx--;
    node* root = new node(curr);
    if(start==end)
        return root;
    int pos = search(inOrder, start, end, curr);
    root->right = buildTree(postOrder, inOrder, pos+1, end);
    root->left = buildTree(postOrder, inOrder, start, pos-1);
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
    int postOrder[]={4, 5, 2, 6, 7, 3, 1};
    int inOrder[]={4, 2, 5, 1, 6, 3, 7};
    node* root = buildTree(postOrder, inOrder, 0, 6);
    display(root);
    return 0;
}