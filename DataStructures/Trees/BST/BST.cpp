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

Node* insert(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

Node* search(Node* root,int data){
    if(root == NULL) return NULL;
    if(root->data == data) return root;
    if(data < root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}

void createBST(Node* &root){
    int data;cin>>data;
    while(data != -1){
        root = insert(root,data);
        cin>>data;
    }
}

void inorder(Node* root){
    if(root == NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

Node* DeleteNode(Node* root, int element){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == element){
        // 0 child  
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child - left
        if(root->left != NULL && root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        // 1 child - right
        if(root->left ==  NULL && root->right != NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        // 2 child
        if(root->left && root->right){
            Node* temp = root;
            Node* leftNode = root->left;
            root = root->right;
            while(root->left != NULL) root = root->left;
            root->left = leftNode;
            root = temp->right;
            delete temp;
            return root;
        }
    }
    else if(root->data > element){
        root->left = DeleteNode(root->left,element);
    }
    else{
        root->right = DeleteNode(root->right,element);
    }
    return root;
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
    inorder(root);
    cout<<endl;

    // Search
    // Node* ans = search(root,112);
    // if(ans){
    //     cout<<"Node is present"<<endl;
    // }
    // else cout<<"NO such node found!!"<<endl;

    // Delete Node:
    root = DeleteNode(root,23);
    cout<<isBST(root)<<endl;
    return 0;
}

// 15 8 20 6 12 17 22 10 18 25 9 11 23 -1