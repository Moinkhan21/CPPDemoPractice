#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ===============================
// Trie Node
// ===============================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int stringNumber;
    bool isTerminal;

    TrieNode(char ch) : data(ch), stringNumber(-1), isTerminal(false) {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// ===============================
// Trie Class
// ===============================
class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i, int& stringNumber) {
        if (i >= word.size()) {
            root->stringNumber = stringNumber;
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1, stringNumber);
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string& word, int& stringNumber) {
        insertUtil(root, word, 0, stringNumber);
    }

    bool isPalindrome(string& s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high]) return false;
            low++; high--;
        }
        return true;
    }

    void searchCase2(TrieNode* node, vector<int>& myPalindrome, string s) {
        if (node->stringNumber != -1) {
            if (isPalindrome(s, 0, s.size() - 1))
                myPalindrome.push_back(node->stringNumber);
        }

        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                s.push_back(i + 'a');
                searchCase2(node->children[i], myPalindrome, s);
                s.pop_back();
            }
        }
    }

    void search(string& word, vector<int>& myPalindrome) {
        TrieNode* curr = root;

        // Case 1
        for (int i = 0; i < word.size(); ++i) {
            if (curr->stringNumber != -1) {
                if (isPalindrome(word, i, word.size() - 1))
                    myPalindrome.push_back(curr->stringNumber);
            }

            int index = word[i] - 'a';
            if (!curr->children[index])
                return;

            curr = curr->children[index];
        }

        // Case 2
        searchCase2(curr, myPalindrome, "");
    }
};

// ===============================
// Palindrome Pairs
// ===============================
vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    Trie trie;

    for (int i = 0; i < words.size(); ++i) {
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        trie.insert(rev, i);
    }

    for (int i = 0; i < words.size(); ++i) {
        vector<int> myPalindrome;
        trie.search(words[i], myPalindrome);

        for (auto it : myPalindrome) {
            if (it != i)
                ans.push_back({i, it});
        }
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};

    vector<vector<int>> result = palindromePairs(words);

    cout << "Palindrome Pairs:\n";
    for (auto& p : result) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}
