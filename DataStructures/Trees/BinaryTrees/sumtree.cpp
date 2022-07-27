#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cin>>data;
    if(data == -1) return NULL;
    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

pair<bool,int> sumofTree(node* root){
    if(root == NULL){
        return make_pair(true,0);
    }
    if(root->left == NULL && root->right == NULL){
        return make_pair(true,root->data);
    }
    pair<bool,int> l = sumofTree(root->left);
    pair<bool,int> r = sumofTree(root->right);
    bool check = root->data == (l.second+r.second);

    if(l.first && r.first && check){
        return make_pair(true,root->data+l.second+r.second);
    }
    else return make_pair(false,root->data+l.second+r.second);
}

bool isSumTree(node* root){
    pair<bool,int> ans = sumofTree(root);
    return ans.first;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<isSumTree(root)<<endl;
    return 0;
}

// 48 9 3 -1 -1 6 -1 -1 15 7 -1 -1 8 -1 -1