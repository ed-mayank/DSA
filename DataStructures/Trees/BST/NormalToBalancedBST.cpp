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

void inorder(Node* root, vector<int>& v){
    if(root == NULL) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* createBalancedBST(Node* root, vector<int>& v, int start, int end){
    int mid = (end+start)/2;
    if(end < start) return NULL;
    if(root == NULL){
        root = new Node(v[mid]);
        return root;
    }
    root->left = createBalancedBST(root->left,v,start,mid-1);
    root->right = createBalancedBST(root->right,v,mid+1,end);
    return root;
}

Node* Balance(Node* root){
    vector<int> v;
    inorder(root,v);
    Node* newRoot = NULL;
    newRoot = createBalancedBST(root,v,0,v.size()-1);
    return newRoot;
}

void LevelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right) q.push(temp->right);
        }
    }
}


int main(){
    Node* root = NULL;
    createBST(root);
    LevelOrderTraversal(root);
    Node* ans = Balance(root);
    LevelOrderTraversal(ans);
    return 0;
}