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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    
    return (max(height(root->left),height(root->right))+1);
}

int Diameter(node* root){  // O(n^2) time complexity
    if(root == NULL) return 0;
    int op1 = Diameter(root->left);
    int op2 = Diameter(root->right);
    int op3 = height(root->left)+height(root->right)+1;

    int ans = max(op3,max(op1,op2));
    return ans;
}


pair<int,int> fastDiameter(node* root){ // merging height and diameter code;
    if(root == NULL) return make_pair(0,0);
    pair<int,int> op1 = fastDiameter(root->left);
    pair<int,int> op2 = fastDiameter(root->right);
    int op3 = op1.second + op2.second + 1;
    int max_dia = max(op3,max(op1.first,op2.first));
    int max_hei = max(op1.second,op2.second)+1;

    return make_pair(max_dia,max_hei);
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<Diameter(root)<<endl;
    cout<<fastDiameter(root).first<<endl;
    return 0;
}