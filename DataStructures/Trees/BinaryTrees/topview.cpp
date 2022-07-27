// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/
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

vector<int> topView(Node *root){
    vector<int> result;
    if(root == NULL) return result;
    int hd=0;
    queue<pair<int,Node*>>q;
    map<int,int>m;
    q.push(make_pair(0,root));
    while(!q.empty()){
        pair<int,Node*> p = q.front();
        q.pop();
        if(m[p.first] == 0){
            m[p.first] = p.second->data;
        }
        if(p.second->left){
            q.push(make_pair(p.first-1,p.second->left));
        }
        if(p.second->right){
            q.push(make_pair(p.first+1,p.second->right));
        }
    }
    for(auto x:m){
        result.push_back(x.second);
    }

    return result;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int>ans = topView(root);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}