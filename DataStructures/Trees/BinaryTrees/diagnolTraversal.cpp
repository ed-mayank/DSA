// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/

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

vector<int> diagnolTraversal(Node *root){
    vector<int> result;
    if(root == NULL) return result;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp){
            if(temp->left) q.push(temp->left);
            result.push_back(temp->data);
            temp = temp->right;
        }
    }
    
    return result;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int>ans = diagnolTraversal(root);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}