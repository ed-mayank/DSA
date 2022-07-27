// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

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
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;

    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void leafs(Node* root, vector<int>& result){
    if(root == NULL) return;
    leafs(root->left,result);
    if(root->left == NULL && root->right == NULL)
        result.push_back(root->data);
    leafs(root->right,result);
}

vector<int> boundaryTraversal(Node* root){
    vector<int>result;
    Node* temp=root;
    result.push_back(temp->data);
    temp = temp->left;
    //left boundary:
    while(temp){
        if(temp->left || temp->right)
            result.push_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp = temp->right;
    }

    // leaf nodes
    leafs(root,result);

    // right boundary
    temp = root;
    vector<int>rightBoundary;
    while(temp->right){
        temp = temp->right;
        if(temp->left || temp->right) 
            rightBoundary.push_back(temp->data);
    }
    for(int i=rightBoundary.size()-1;i>=0;i--){
        result.push_back(rightBoundary[i]);
    }
    return result;
}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    vector<int>ans = boundaryTraversal(root);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}

//  1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1
//  1 2 4 -1 -1 5 10 11 -1 -1 12 -1 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1