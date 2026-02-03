#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// =====================================================
// CLASS: TrieNode
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[58];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 58; ++i)
            children[i] = nullptr;
    }
};

// =====================================================
// CLASS: Trie
// =====================================================
class Trie {
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i) {
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'A';

        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    int searchUtil(TrieNode* root, string& word, int i) {
        if (i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'A';

        if (root->children[index])
            return searchUtil(root->children[index], word, i + 1);
        else if (islower(word[i]))
            return searchUtil(root, word, i + 1);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string& word) {
        insertUtil(root, word, 0);
    }

    bool search(string& word) {
        return searchUtil(root, word, 0);
    }
};

// =====================================================
// FUNCTION: Camel Case Match
// =====================================================
vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    Trie trie;

    trie.insert(pattern);

    for (auto& query : queries) {
        ans.push_back(trie.search(query));
    }
    return ans;
}

// =====================================================
// MAIN
// =====================================================
int main() {
    vector<string> queries = {
        "FooBar",
        "FooBarTest",
        "FootBall",
        "FrameBuffer",
        "ForceFeedBack"
    };

    string pattern = "FB";

    vector<bool> result = camelMatch(queries, pattern);

    for (bool val : result)
        cout << (val ? "true" : "false") << " ";

    return 0;
}
