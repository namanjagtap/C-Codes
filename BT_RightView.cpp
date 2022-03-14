#include <iostream>
#include <queue>
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

void rightView(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            node* temp = q.front();
            q.pop();
            if(i==n){
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right)
                q.push(temp->right);
        }
    }
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
    rightView(root);
    return 0; 
}