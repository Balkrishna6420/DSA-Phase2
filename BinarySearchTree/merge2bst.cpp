void inorder(TreeNode *root, vector<int> &in) {
    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }

    while (i < a.size()) ans.push_back(a[i++]);
    while (j < b.size()) ans.push_back(b[j++]);

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    vector<int> bst1, bst2;

    inorder(root1, bst1);
    inorder(root2, bst2);

    return mergeArrays(bst1, bst2);
}
//timE and space complexity here is o(m+n);


//using linked list approach wheer time compl is o(n+m) but space is o(h1+h2)
vector<int> mergeBST(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    vector<int> ans;

    while (root1 || root2 || !s1.empty() || !s2.empty()) {

        // Push left nodes of both trees
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }

        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }

        // Compare top elements
        if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)) {
            root1 = s1.top(); s1.pop();
            ans.push_back(root1->data);
            root1 = root1->right;
        } else {
            root2 = s2.top(); s2.pop();
            ans.push_back(root2->data);
            root2 = root2->right;
        }
    }

    return ans;
}
