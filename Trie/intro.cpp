#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    //constructor
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie(){//constructor
        root=new TrieNode('\0');
    }
    //INSERTION
    void insertUtil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //assumptiopn word will be in CAPS
        int index=word[0]-'A';
        TrieNode *child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursion
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
//SEARCHING
    bool searchUtil(TrieNode *root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode*child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            //absent
            return false;
        }
        //recursion
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }
    // DELETE (only unmark terminal)
bool deleteUtil(TrieNode* root, string word) {
    // base case
    if(word.length() == 0) {
        if(root->isTerminal) {
            root->isTerminal = false;
            return true;
        }
        return false; // word not present
    }

    int index = word[0] - 'A';
    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        // word not present
        return false;
    }

    // recursion
    return deleteUtil(child, word.substr(1));
}

bool deleteWord(string word) {
    return deleteUtil(root, word);
}

};
int main(){
    Trie *t=new Trie();
    t->insertWord("BALA");
    cout<<"present or not"<<t->searchWord("BALA")<< endl;
    t->deleteWord("BALA");

    cout << "After delete: " << t->searchWord("BALA") << endl;
    return 0;
}
//i case of deletion just mark is terminal as false 