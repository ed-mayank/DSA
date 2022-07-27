// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

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

Node* lca(Node* root, int n1, int n2){
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left,n1,n2);
    Node* rightAns = lca(root->right,n1,n2);
    
    if(leftAns && rightAns) return root;
    else if(leftAns && !rightAns) return leftAns;
    else if(!leftAns && rightAns) return rightAns;
    else return NULL;
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // Seperator to show levels
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    Node* ans = lca(root,8,9);
    if(ans != NULL)
    cout<<ans->data<<endl;
    return 0;
}