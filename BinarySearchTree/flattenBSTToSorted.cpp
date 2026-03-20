#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorderVal;
    
    // store inorder sorted values
    inorder(root, inorderVal);
    
    int n = inorderVal.size();  // Moved after inorder call
    
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;
    
    for(int i = 1; i < n; i++){  // Changed to i < n
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    curr->left = NULL;
    curr->right = NULL;
    
    return newRoot;
}