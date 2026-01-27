#include <iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
            this -> data = d;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            this -> isTerminal = false;
        }

};

void insertWord(TrieNode* root, string word) {
    //Base case
    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //Present
    if(root -> children[index] != NULL) {
        child = root -> children[index];
    }
    else {
        //Not present
        child = new TrieNode(ch);
        root -> children[index] = child;
    }

    //Recursion will handle
    insertWord(child, word.substr(1)); 
}

bool searchWord(TrieNode* root, string word) {
    //Base case
    if(word.length() == 0) {
        return root -> isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    //Present
    if(root -> children[index] != NULL) {
        child = root -> children[index];
    }
    else {
        return false;
    }

    //Rec call
    searchWord(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-'); 
    
    //root -> insertWord("coding");
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");

    if(searchWord(root, "coding")) {
        cout << "present" << endl;
    }
    else {
        cout << "absent" << endl;
    }

    return 0;
}