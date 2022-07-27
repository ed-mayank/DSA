// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
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

pair<int,int> solve(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int,int> l = solve(root->left);
    pair<int,int> r = solve(root->right);
    pair<int,int> ans = make_pair(root->data+l.second+r.second,max(l.first,l.second)+max(r.first,r.second));
    return ans;
}

int getMaxSum(Node *root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<getMaxSum(root)<<endl;
    return 0;
}