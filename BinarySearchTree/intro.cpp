
//create bst
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->  left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}


Node* insertIntoBST(Node* &root,int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;  
    }
    if(d>root->data){
        //right part me insert karn ahai
         root->right=insertIntoBST(root->right,d);
    }
    else{
        //left part me insert karna hai
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }

}
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BSt"<<endl;
    takeInput(root);
    cout<<"printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<"printing the BST"<<endl;
    inorder(root);
    cout<<"printing the BST"<<endl;
    preorder(root);
    cout<<"printing the BST"<<endl;
    postorder(root);
    cout<<"min val is"<<minVal(root)->data<<endl;
    cout<<"max val is "<<maxVal(root)->data<<endl;
    return 0;

}