// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data =d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

Node* solve(Node* root, int k, int& ans, int& count, int node){
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    Node* leftAns = solve(root->left,k,ans,count,node);
    Node* rightAns = solve(root->right,k,ans,count,node);

    if(leftAns || rightAns){
        count++;
        if(count == k) ans=root->data;
    }
    else return NULL;
}

int kthAncestor(Node *root, int k, int node){
    int ans=-1;
    int count=0;
    solve(root,k,ans,count,node);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<kthAncestor(root,6,11)<<endl;
    return 0;
}