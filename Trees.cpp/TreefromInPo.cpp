/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  void createMapping(vector<int> &inorder, map<int,int> &nodeToIndex, int n){
      for(int i = 0; i < n; i++){
          nodeToIndex[inorder[i]] = i;  // Changed == to =
      }
  }
  
  Node* solve(vector<int> &inorder, vector<int> &postorder, int &index,
              int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex){
      // base case
      if(index < 0 || inorderStart > inorderEnd){
          return NULL;
      }
      
      // create a root node for element
      int element = postorder[index--];
      Node* root = new Node(element);
      
      // find element's index in inorder
      int position = nodeToIndex[element];
      
      // recursive calls (right first for postorder)
      root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n, nodeToIndex);
      root->left = solve(inorder, postorder, index, inorderStart, position - 1, n, nodeToIndex);
      
      return root;
  }
  
  Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
      int n = inorder.size();  // Added this line
      int postOrderIndex = n - 1;  // Changed variable name
      map<int,int> nodeToIndex;
      
      // create node to index mapping
      createMapping(inorder, nodeToIndex, n);
      
      Node* ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
      
      return ans;
  }
};