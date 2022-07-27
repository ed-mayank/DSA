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
    cout<<"Enter the data: ";
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to insert in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL); // Seperator to show levels
    while(!q.empty()){
        node* temp = q.front();
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

// Reverse level order traversal:
// 1. Using stack and queues: Modify the level order travesal by instead of printing we will push it into stack.
// 2. Traversing trees first right subtree then left subtree to maintain order.

void reverseLevelOrderTraversal(node* root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            s.push(temp);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            s.push(temp);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        if(temp == NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
    }
    cout<<endl;
}

void Inorder(node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node* root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void Inorder_iter(node* root){
    stack<node*>s;
    node* curr = root;
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout<<curr->data<<" ";
        s.pop();
        curr = curr->right;
    }
}

void Preorder_iter(node* root){
    stack<node*>s;
    node* curr = root;
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

// Approach-1
/*
Use 2 stacks. 
If we see well then reverse postorder traversal is similar to preorder traversal but with first going to right then to left.
Instead of printing modified preorder traversal, we will push it into new stack.
*/
void Postorder_iter1(node* root){
    stack<node*>s1;
    stack<node*>s2;
    node* curr = root;
    while(!s1.empty() || curr){
        while(curr){
            s1.push(curr);
            s2.push(curr);
            curr = curr->right;
        }
        curr = s1.top();
        s1.pop();
        curr = curr->left;
    }

    while(!s2.empty()){
        node* temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}

int main(){
    node *root = NULL;
    root = buildTree(root);
    // 5 7 8 -1 12 -1 -1 13 -1 -1 11 17 -1 -1 -1
    cout<<endl;
    cout<<"Level order: ";
    levelOrderTraversal(root);
    cout<<"Reverse Level order: ";
    reverseLevelOrderTraversal(root);
    
    cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    Postorder(root);
    cout<<endl;
    cout<<"Inorder Iteration: ";
    Inorder_iter(root);
    cout<<endl;
    cout<<"Preorder Iteration: ";
    Preorder_iter(root);
    cout<<endl;
    cout<<"PostOrder Iteration (two stack): ";
    Postorder_iter1(root);
    cout<<endl;
    return 0;
}