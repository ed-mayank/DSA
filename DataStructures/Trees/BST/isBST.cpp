#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};

Node* Insert(Node* root, int element){
    if(root == NULL){
        root = new Node(element);
        return root;
    }

    if(root->data > element){
        root->left = Insert(root->left,element);
    }
    else{
        root->right = Insert(root->right,element);
    }
    return root;
}

void createBST(Node* &root){
    int data;cin>>data;
    while(data != -1){
        root = Insert(root,data);
        cin>>data;
    }
}

bool isBSTUtil(Node* root, int min, int max){
    if(root == NULL) return true;

    if(root->data < min || root->data> max){
        return false;
    }

    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}

bool isBST(Node* root){
    return isBSTUtil(root,INT32_MIN,INT32_MAX);   
}

int main(){
    Node* root = NULL;
    createBST(root);
    // root->left->data = 5;
    cout<<isBST(root)<<endl;
    return 0;
}