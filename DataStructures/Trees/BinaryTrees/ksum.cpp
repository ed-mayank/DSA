// https://practice.geeksforgeeks.org/problems/k-sum-paths/1/

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

void solve(Node* root, int k, int& count, vector<int>& path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);
    int sum=0;
    for(int i=path.size()-1;i>=0;i--){
        sum = sum+path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}

int sumK(Node *root,int k){
    vector<int>path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<sumK(root,18)<<endl;
    return 0;
}