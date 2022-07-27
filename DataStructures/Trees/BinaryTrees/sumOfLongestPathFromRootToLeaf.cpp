// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

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
    cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void solve(Node* root, int sum,int len,int& maxSum,int& maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = sum;
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left,sum,len+1,maxSum,maxLen);
    solve(root->right,sum,len+1,maxSum,maxLen);
}

int sumOfLongRootToLeafPath(Node *root){
    int sum=0,len=0,maxSum=INT32_MIN,maxLen=INT32_MIN;
    solve(root,sum,len,maxSum,maxLen);
    return maxSum;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<sumOfLongRootToLeafPath(root)<<endl;
    return 0;
}