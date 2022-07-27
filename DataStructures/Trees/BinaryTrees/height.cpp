#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cin>>data;
    if(data == -1) return NULL;
    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    
    return (max(height(root->left),height(root->right))+1);
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<height(root)<<endl;
    return 0;
}