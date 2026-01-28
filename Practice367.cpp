#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===============================
// Trie Node Definition
// ===============================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

// ===============================
// Insert Word into Trie
// ===============================
void insertWord(TrieNode* root, string word) {

    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

// ===============================
// Search Word in Trie
// ===============================
bool searchWord(TrieNode* root, string word) {

    if (word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';

    if (root->children[index] == NULL)
        return false;

    return searchWord(root->children[index], word.substr(1)); // ✅ FIXED
}

// ===============================
// Find Longest Common Prefix
// ===============================
void findLCP(string first, string& ans, TrieNode* root) {

    if (root->isTerminal)
        return;

    for (int i = 0; i < first.length(); i++) {

        char ch = first[i];

        if (root->childCount == 1) {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root->children[index];
        }
        else {
            break;
        }

        if (root->isTerminal)
            break;
    }
}

// ===============================
// LCP using Trie
// ===============================
string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty())
        return "";

    TrieNode* root = new TrieNode('-');

    for (int i = 0; i < strs.size(); i++) {
        insertWord(root, strs[i]);
    }

    string ans = "";
    string first = strs[0];
    findLCP(first, ans, root);

    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest Common Prefix: "
         << longestCommonPrefix(strs) << endl;

    return 0;
}
