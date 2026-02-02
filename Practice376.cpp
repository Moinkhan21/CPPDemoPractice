#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// =====================================================
// Comparator for Min-Heap
// =====================================================
class comp {
public:
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) const {
        if (a.first == b.first)
            return a.second < b.second;   // reverse lex order
        return a.first > b.first;         // min-heap by frequency
    }
};

// =====================================================
// CLASS: TrieNode
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int freq;

    TrieNode(char ch) : data(ch), isTerminal(false), freq(0) {
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
            ++root->freq;
            return;
        }

        int index = word[i] - 'a';

        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    void traverseUtil(
        TrieNode* root,
        string& s,
        priority_queue<pair<int, string>,
        vector<pair<int, string>>, comp>& pq,
        int& k) {

        if (!root) return;

        if (root->isTerminal) {
            if (pq.size() < k) {
                pq.push({root->freq, s});
            }
            else if (pq.size() == k &&
                    (root->freq > pq.top().first ||
                    (root->freq == pq.top().first &&
                     s < pq.top().second))) {
                pq.pop();
                pq.push({root->freq, s});
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                s.push_back(i + 'a');
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back(); // backtracking
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(const string& word) {
        insertUtil(root, word, 0);
    }

    void traverse(priority_queue<pair<int, string>,
                  vector<pair<int, string>>, comp>& pq,
                  int& k) {
        string s;
        traverseUtil(root, s, pq, k);
    }
};

// =====================================================
// FUNCTION: Top K Frequent Words
// =====================================================
vector<string> topKFrequent(vector<string>& words, int k) {
    Trie trie;
    vector<string> ans;

    for (auto& word : words)
        trie.insert(word);

    priority_queue<pair<int, string>,
        vector<pair<int, string>>, comp> pq;

    trie.traverse(pq, k);

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// =====================================================
// MAIN
// =====================================================
int main() {
    vector<string> words = {
        "i", "love", "leetcode", "i", "love", "coding"
    };
    int k = 2;

    vector<string> result = topKFrequent(words, k);

    cout << "Top " << k << " frequent words:\n";
    for (auto& word : result)
        cout << word << " ";

    return 0;
}
