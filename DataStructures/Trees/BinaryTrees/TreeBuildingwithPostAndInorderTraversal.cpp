// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/

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

// Using mapping to findPosition

void mapPosition(int in[], int n, map<int,int>& m){
    for(int i=0;i<n;i++){
        m[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int& index, int inorderStart, int inorderEnd, int n,map<int,int>& m){
    if(index < 0 || inorderStart > inorderEnd) return NULL;
    int element = post[index--];
    Node* root = new Node(element);
    int position = m[element];

    root->right = solve(in,post,index,position+1,inorderEnd,n,m);
    root->left = solve(in,post,index,inorderStart,position-1,n,m);
    
    return root;
}

Node* buildTree(int in[],int post[], int n){
    int index=n-1;
    int inorderStart=0;
    int inorderEnd=n-1;
    map<int,int> m;
    mapPosition(in,n,m);
    Node* ans = solve(in,post,index,inorderStart,inorderEnd,n,m);
    return ans;
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return;
}

int main(){
    int in[] =  {4, 2, 11, 10, 12, 5, 1, 6, 8, 3, 7, 9};
    int post[] ={4, 11, 12, 10, 5, 2, 8, 6, 9, 7, 3, 1};
    Node* root = buildTree(in,post,12);
    if(root == NULL) cout<<"Something wrong\n";
    preOrderTraversal(root);
    return 0;
}

// 1 2 4 5 10 11 12 3 6 8 7 9 