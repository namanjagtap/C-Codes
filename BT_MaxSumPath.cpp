#include <bits/stdc++.h>
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

int maxSumPathUtil(node* root, int &ans){
    if(root==NULL)
        return 0;
    int left = maxSumPathUtil(root->left, ans);
    int right = maxSumPathUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), 
                    max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, 
                            max(root->data + left, root->data + right));

    return singlePathSum;
}

int MaxSumPath(node* root){
    int ans = INT_MIN;
    maxSumPathUtil(root, ans);
    return ans;
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
    cout<<MaxSumPath(root)<<endl;
    return 0;
}