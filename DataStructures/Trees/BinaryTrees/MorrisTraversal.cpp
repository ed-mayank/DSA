// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

/*
Morris Traversal to print Inorder traversal: 

Pseudocode:
curr = root;
while(curr != NULL):
    if(curr->left does not exist):
        print curr->data
        curr = curr->right
    else:
        predecessor = find(curr);  // Once go left of curr and then go to right of curr till either curr->right == NULL or curr->right == curr;
        if(predecessor->right == NULL):
            predecessor->right = curr;
            curr = curr->left;
        else:
            predecessor->right = NULL;
            print curr->data;
            curr = curr->right;
*/


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

    if(data == -1){
        return NULL;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void InorderTraversal(Node* root){
    if(root == NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

void MorrisTraversal_inorder(Node* root){
    Node* curr;
    Node* pre;
    curr = root;
    while(curr){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

void MorrisTraversal_preorder(Node* root){
    Node* curr;
    Node* pre;
    curr = root;
    while(curr){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                cout<<curr->data<<" ";
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void MorrisTraversal_postorder(Node* root){
    Node* curr;
    Node* pre;
    curr = root;
    vector<int>postorder;
    while(curr){
        if(curr->right == NULL){
            postorder.push_back(curr->data);
            curr = curr->left;
        }
        else{
            pre = curr->right;
            while(pre->left != NULL && pre->left != curr){
                pre = pre->left;
            }
            if(pre->left == NULL){
                postorder.push_back(curr->data);
                pre->left = curr;
                curr = curr->right;
            }
            else{
                pre->left = NULL;
                curr = curr->left;
            }
        }
    }

    vector<int>::reverse_iterator it = postorder.rbegin();
    for(it ;it != postorder.rend();it++){
        cout<<*it<<" ";
    }
}


int main(){
    Node *root = NULL;
    root = buildTree(root);
    cout<<"Inorder: ";
    MorrisTraversal_inorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    MorrisTraversal_preorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    MorrisTraversal_postorder(root);
    cout<<endl;
    return 0;
}