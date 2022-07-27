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

Node* buildTree(Node* root){
    int data;cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

Node* path(Node* root,int n, vector<int>& p){
    if(root == NULL) return NULL;
    if(root->data == n){
        p.push_back(root->data);
        return root;
    }
    Node* leftAns = path(root->left,n,p);
    Node* rightAns = path(root->right,n,p);
    if(leftAns || rightAns){
        p.push_back(root->data);
        return root;
    }
    else return NULL;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int>ans;
    path(root,12,ans);
    if(ans.size() == 0) cout<<"Node does not exist"<<endl;
    else{
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}