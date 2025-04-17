// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
    
    
//   public:
//     // Function to return the diameter of a Binary Tree.
//     pair<int,int> diameterFast(Node* root) {
//         //base case
//         if(root == NULL) {
//             pair<int,int> p = make_pair(0,0);
//             return p;
//         }
        
//         pair<int,int> left = diameterFast(root->left);
//         pair<int,int> right = diameterFast(root->right);
        
//         int op1 = left.first;
//         int op2 = right.first;
//         int op3 = left.second + right.second + 1;
        
//         pair<int,int> ans;
//         ans.first = max(op1, max(op2, op3));;
//         ans.second = max(left.second , right.second) + 1;

//         return ans;
//     }
//     int diameter(Node* root) {
    
//         return diameterFast(root).first;
        
//     }
// };
// //above code is optimal

// int height(struct TreeNode<int>* node){
//         //base case
//         if(node == NULL) {
//             return 0;
//         }
        
//         int left = height(node ->left);
//         int right = height(node->right);
        
//         int ans = max(left, right) + 1;
//         return ans;
//     }
// int diameterOfBinaryTree(TreeNode<int> *root){
// 	// Write Your Code Here.
//     if(root==NULL){
//         return 0;
//     }
//     int op1=diameterOfBinaryTree(root->left);
//     int op2=diameterOfBinaryTree(root->right);
//     int op3=height(root->left)+height(root->right);
//     int ans=max(op1,max(op2,op3));
//     return ans;
// }
// //this code tc is of o(n^2)