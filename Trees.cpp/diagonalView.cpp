// /* A binary tree node
// struct Node
// {
//     int data;
//     Node* left, * right;
// }; */

// class Solution {
//   public:
//     vector<int> diagonal(Node *root) {
//         // code here
//         queue<Node*> q;
//         vector<int> ans;
//         q.push(root);
//         while(!q.empty()){
//             Node *tmp = q.front();
//             q.pop();
//             while(tmp){
//                 ans.push_back(tmp->data);
//                 if(tmp->left){
//                     q.push(tmp->left);
//                 }
//                 tmp = tmp->right;
//             }
//         }
//         return ans;
//     }
// };