#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =====================================================
// CLASS: TrieNode
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// =====================================================
// CLASS: Trie
// =====================================================
class Trie {
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, const string& word, int i) {
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';

        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    // 🔹 Returns index where root word ends, else -1
    int searchUtil(TrieNode* root, const string& word, int i) {
        if (root->isTerminal)
            return i;

        if (i >= word.size())
            return -1;

        int index = word[i] - 'a';

        if (root->children[index])
            return searchUtil(root->children[index], word, i + 1);

        return -1;
    }

    bool startWithUtil(TrieNode* root, const string& word, int i) {
        if (i >= word.size())
            return true;

        int index = word[i] - 'a';

        if (root->children[index])
            return startWithUtil(root->children[index], word, i + 1);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(const string& word) {
        insertUtil(root, word, 0);
    }

    // 🔹 Return index instead of bool
    int search(const string& word) {
        return searchUtil(root, word, 0);
    }

    bool startWith(const string& prefix) {
        return startWithUtil(root, prefix, 0);
    }
};

// =====================================================
// FUNCTION: replaceWords
// =====================================================
string replaceWords(vector<string>& dictionary, string sentence) {
    string ans;
    Trie trie;

    // Insert dictionary roots
    for (auto& root : dictionary)
        trie.insert(root);

    int start = 0, end = 0;

    while (end < sentence.size()) {
        if (sentence[end] == ' ' || end == sentence.size() - 1) {

            int len = (end == sentence.size() - 1)
                        ? sentence.size() - start
                        : end - start;

            string word = sentence.substr(start, len);

            int trieMatchIndex = trie.search(word);

            if (trieMatchIndex != -1)
                ans += word.substr(0, trieMatchIndex);
            else
                ans += word;

            if (sentence[end] == ' ')
                ans += " ";

            start = end + 1;
        }
        ++end;
    }
    return ans;
}

// =====================================================
// MAIN
// =====================================================
int main() {
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << replaceWords(dictionary, sentence) << endl;

    return 0;
}
