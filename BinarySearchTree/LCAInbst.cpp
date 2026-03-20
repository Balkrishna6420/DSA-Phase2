/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    if(root->data>P->data && root->data>Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    return root;
}
//or
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    //iterative way so that spac complexity is utilised
    while(root!=NULL){
        if(root->data<P->data && root->data<Q->data){
            root=root->right;
        }
        else if(root->data>P->data && root->data>Q->data){
            root=root->left;
        }else{
            return root;
        }
    }
}