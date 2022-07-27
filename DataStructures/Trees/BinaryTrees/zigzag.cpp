// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/

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
    cout<<"Enter data: ";
    cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;

    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> zigzag(Node* root){
    vector<int>result;
    if(root == NULL) return result;
    queue<Node*>q;
    bool leftToRight = true;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            int index = leftToRight ? i : size-i-1;
            Node* fnode = q.front();
            q.pop();
            temp[index] = fnode->data;
            if(fnode->left){
                q.push(fnode->left);
            }
            if(fnode->right){
                q.push(fnode->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto x:temp){
            result.push_back(x);
        }
    }
    return result;
}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    vector<int> v = zigzag(root);
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}

//  1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1