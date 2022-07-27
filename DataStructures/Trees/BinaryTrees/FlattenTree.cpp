// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/

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

Node* buildTree(Node* root){
    int data;cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void flatten_preorder(Node *root){
    Node* curr = root;
    Node* pre;
    while(curr){
        if(curr->left == NULL){
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL){
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
        }
    } 
}

//wrong
void flatten_inorder(Node* root){
    Node* curr = root;
    Node* pre;
    while(curr){
        if(curr->left == NULL){
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right == curr;
                curr = curr->left;
            }
            else{
                curr->left = NULL;
                Node* post = curr->right;
                while(post->left != NULL){
                    post = post->left;
                }
                Node* temp = curr->right;
                curr->right = post;
                curr = temp;
            }

        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    flatten_preorder(root);
    // flatten_inorder(root);
    while(root){
        cout<<root->data<<" ";
        if(root->left) cout<<"Error ";
        root = root->right;
    }
    cout<<endl;
    return 0;
}