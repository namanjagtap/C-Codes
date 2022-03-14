#include <iostream>
#include <vector>
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

bool getPath(node* root, int key, vector<int> &path){
    if(root==NULL)
        return false;

    path.push_back(root->data);
    if(root->data==key)
        return true;
    
    if(getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;
    
    path.pop_back();
    return false;
}

int LCA(node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() && pc<path2.size();pc++){
        if(path1[pc] != path2[pc])
            break;
    }
    return path1[pc-1];
}

//Optimised Way
node* LCA2(node* root, int n1, int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    node* leftptr = LCA2(root->left, n1, n2);
    node* rightptr = LCA2(root->right, n1, n2);

    if(leftptr && rightptr)
        return root;
    if(leftptr!=NULL)
        return leftptr;
    return rightptr;
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
    int n1=5, n2=6;
    node* lca = LCA2(root, n1, n2);
    if(lca==NULL)
        cout<<"LCA doesn't exist"<<endl;
    else
        cout<<"LCA is "<<lca->data<<endl;
    return 0;
}