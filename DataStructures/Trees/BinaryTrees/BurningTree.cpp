// https://practice.geeksforgeeks.org/problems/burning-tree/1

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

Node* parentToNodeMapping(Node* root, map<Node*, Node*>& parentToNode,int target){
    queue<Node*>q;
    Node* targetNode;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->data == target) targetNode = temp;
        if(temp->left){
            q.push(temp->left);
            parentToNode[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            parentToNode[temp->right] = temp;
        }
    }
    parentToNode[root] = NULL;
    return targetNode;
}



int minTime(Node* root, int target){
    map<Node*, Node*> parentToNode;
    Node* targetNode;
    targetNode = parentToNodeMapping(root,parentToNode,target);
    int time=0;
    map<Node*,bool> visited;
    queue<Node*>q;
    q.push(targetNode);
    visited[targetNode] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left && visited[temp->left] == false){
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && visited[temp->right] == false){
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(parentToNode[temp] && visited[parentToNode[temp]] == false){
                q.push(parentToNode[temp]);
                visited[parentToNode[temp]] = true;
            }
        }
        if(q.size()>0) time++;
    }
    return time;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    int target;
    cout<<"Enter Target: ";
    cin>>target;
    cout<<minTime(root,target)<<endl;
    return 0;
}