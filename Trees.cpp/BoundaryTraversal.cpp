#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    void traverseLeft(Node*root,vector<int>&ans){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }else{
            traverseLeft(root->right,ans);
        }
    }
    void traverseLeaf(Node*root,vector<int>&ans){
        //bse case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    void traverseRight(Node*root,vector<int>&ans){
        //base casew
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            traverseRight(root->right,ans);
        }else{
            traverseRight(root->left,ans);
        }
        //wapas aane pe 
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        //left prt print /store
        traverseLeft(root->left,ans);
        //traverseLeafNode
        //left subtree
        traverseLeaf(root->left,ans);
        //right Subtree
        traverseLeaf(root->right,ans);
        //right part print in reverse order
        traverseRight(root->right,ans);
        
        return ans;
    }
};