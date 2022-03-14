#include <iostream>
#include <queue>
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

void levelOrderTraversal(struct node* root, int level){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int k=0, sum=0;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n!=NULL){
            if(k==level){
                sum+=n->data;
            }
            cout<<n->data<<" ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            k++;
        }
    }
    cout<<endl<<k;
    cout<<endl<<"Sum of nodes at K level:- "<<sum<<endl;
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
    
    levelOrderTraversal(root, 0);
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