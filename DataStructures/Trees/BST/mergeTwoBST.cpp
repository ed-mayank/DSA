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

void convertIntoSortedDLL(Node* root, Node*& head){
    if(root == NULL) return;

    convertIntoSortedDLL(root->right,head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convertIntoSortedDLL(root->left,head);
}

Node* mergeLinkedList(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;
    Node* temp = head;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                temp = head;
                head1 = head1->right;
            }
            else{
                tail = head1;
                head1 = head1->right;
                head->right = tail;
                tail->left = head;
                head = tail;
            }
        }
        else{
            if(head == NULL){
                head = head1;
                temp = head;
                head2 = head2->right;
            }
            else{
                tail = head2;
                head2 = head2->right;
                head->right = tail;
                tail->left = head;
                head = tail;
            }
        }
    }
    while(head1 != NULL){
        tail = head1;
        head1 = head1->right;
        head->right = tail;
        tail->left = head;
        head = tail;
    }

    while(head2 != NULL){
        tail = head2;
        head2 = head2->right;
        head->right = tail;
        tail->left = head;
        head = tail;
    }

    return temp;
}

int countNodes(Node* head){
    int count=0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->right;
    }

    return count;
}

Node* sortedLLTOBST(Node* head, int n){
    cout<<n<<endl;
    // base case
    if(n<=0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLTOBST(head,(n/2));

    Node* root = head;
    head = head->right;
    root->left = left;

    root->right = sortedLLTOBST(head,n-(n/2)-1);
    return root;
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

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root1 = NULL;
    createBST(root1);
    Node* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;


    Node* root2 = NULL;
    createBST(root2);
    Node* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;


    cout<<"First BST to LL: ";
    Node* temp = head1;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;


    cout<<"Second BST to LL: ";
    temp = head2;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

    //Merge
    Node* head = NULL;
    head = mergeLinkedList(head1,head2);
    cout<<"Merged BST to LL: ";
    head->left = NULL;
    temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

    //Sorted Merged LL to BST
    int count = countNodes(head);
    Node* newRoot = sortedLLTOBST(head,count);
    // cout<<"Level order of merged BST: ";
    // LevelOrderTraversal(newRoot);
    // cout<<"Inorder of merged BST: ";
    // inorder(newRoot);
    cout<<endl;
    cout<<newRoot->data<<endl;
    return 0;
}

// 10 3 12 19 -1
// 6 4 22 -1