// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

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

int findPosition(int in[], int startIndex, int endIndex, int n){
    for(int i=startIndex;i<=endIndex;i++){
        if(in[i] == n) return i;
    }
    return -1;
}

// Using mapping to findPosition

void mapPosition(int in[], int n, map<int,int>& m){
    for(int i=0;i<n;i++){
        m[in[i]] = i;
    }
}

Node* solve(int in[], int pre[], int& index, int inorderStart, int inorderEnd, int n,map<int,int>& m){
    if(index >= n || inorderStart > inorderEnd) return NULL;
    int element = pre[index++];
    Node* root = new Node(element);
    int position = m[element];

    root->left = solve(in,pre,index,inorderStart,position-1,n,m);
    root->right = solve(in,pre,index,position+1,inorderEnd,n,m);
    return root;
}

Node* buildTree(int in[],int pre[], int n){
    int index=0;
    int inorderStart=0;
    int inorderEnd=n-1;
    map<int,int> m;
    mapPosition(in,n,m);
    Node* ans = solve(in,pre,index,inorderStart,inorderEnd,n,m);
    return ans;
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
    return;
}

int main(){
    int in[] = {4, 2, 11, 10, 12, 5, 1, 6, 8, 3, 7, 9};
    int pre[] ={1, 2 ,4, 5 ,10, 11, 12, 3, 6, 8, 7, 9};
    Node* root = buildTree(in,pre,12);
    postOrderTraversal(root);
    return 0;
}