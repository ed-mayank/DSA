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

Node* construct(vector<int> pre, int start, int end){
    if(start > end) return NULL;
    if(start == end){
        Node* root = new Node(pre[start]);
        return root;
    }
    int mid=end;
    int val = pre[start];
    for(int i=start;i<=end;i++){
        if(pre[i] > val){
            mid = i;
            break;
        }
    }
    if(pre[mid] < val) mid++;
    Node* root = new Node(val);
    root->left = construct(pre,start+1,mid-1);
    root->right = construct(pre,mid,end);
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


Node* createBSTFromPreorder(vector<int> pre, int min, int max, int& index){
    if(index >= pre.size()) return NULL;

    // int val = pre[index++];
    
    if(pre[index] < min || pre[index] > max){
        return NULL;
    }
    Node* root = NULL;
    root = new Node(pre[index++]);
    root->left = createBSTFromPreorder(pre,min,root->data,index);
    root->right = createBSTFromPreorder(pre,root->data,max,index);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    // Write your code here.

    //Approach 1
    // return construct(preorder,0,preorder.size()-1);

    //Approach 2
    int index=0;
    return createBSTFromPreorder(preorder,INT_MIN,INT_MAX,index);
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
    vector<int> pre = {20,10,5,15,13,35,30,42};
    root = preorderToBST(pre);
    LevelOrderTraversal(root);
    inorder(root);
    return 0;
}