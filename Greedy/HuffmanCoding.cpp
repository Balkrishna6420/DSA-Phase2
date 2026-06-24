//hardest
class Node{
public:
    int freq;
    int idx;      // earliest character index in this subtree
    Node *left;
    Node *right;

    Node(int f, int i){
        freq = f;
        idx = i;
        left = NULL;
        right = NULL;
    }
};

class cmp{
public:
    bool operator()(Node *a, Node *b){

        if(a->freq == b->freq)
            return a->idx > b->idx;

        return a->freq > b->freq;
    }
};

class Solution {
public:

    void preorder(Node *root, vector<string> &ans, string code){

    if(root->left == NULL && root->right == NULL){

        if(code.empty())
            ans.push_back("0");
        else
            ans.push_back(code);

        return;
    }

    if(root->left)
        preorder(root->left, ans, code + "0");

    if(root->right)
        preorder(root->right, ans, code + "1");
}

    vector<string> huffmanCodes(string &s, vector<int> f) {

        priority_queue<Node*, vector<Node*>, cmp> pq;

        int n = s.size();

        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], i));
        }

        while(pq.size() > 1){

            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *parent = new Node(
                left->freq + right->freq,
                min(left->idx, right->idx)
            );

            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        vector<string> ans;

        preorder(pq.top(), ans, "");

        return ans;
    }
};
//tc o(nlogn) sc is o(n);