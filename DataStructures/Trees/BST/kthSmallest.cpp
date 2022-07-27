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

void inorder(Node* root, int &k,int &ans){
    if(root == NULL) return;
    inorder(root->left,k,ans);
    cout<<root->data<<" ";
    k--;
    if(k == 0 && ans==0){
        ans = root->data;
    }
    inorder(root->right,k,ans);
}
int kthSmallest(Node* root, int k) {
    // Write your code here.

    int ans=-1;
    inorder(root,k,ans);
    return ans;
}


int main(){
    Node* root = NULL;
    createBST(root);
    int ans = kthSmallest(root,13);
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}