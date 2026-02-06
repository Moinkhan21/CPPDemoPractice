#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// =====================================================
// CLASS: comp (Custom Comparator for Min Heap)
// -----------------------------------------------------
// PURPOSE:
//   Defines ordering for priority_queue used to
//   keep TOP K frequent words.
//
// RULES:
//   • Smaller frequency → higher priority (min-heap)
//   • If frequencies are equal:
//       → lexicographically larger word has
//         higher priority (so smaller word survives)
//
// WHY THIS COMPARATOR?
//   • We want to REMOVE:
//       - least frequent words
//       - or lexicographically larger ones
// =====================================================
class comp {
public:
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) const {

        // If frequency same, compare words
        if (a.first == b.first)
            return a.second < b.second;   // reverse lex order

        // Smaller frequency comes first (min heap)
        return a.first > b.first;
    }
};

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a node in the Trie.
//
// DATA MEMBERS:
//   • data        → character stored
//   • children[] → pointers to next characters (a–z)
//   • isTerminal → marks end of a word
//   • freq       → frequency of the word ending here
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
// -----------------------------------------------------
// PURPOSE:
//   Stores words and their frequencies efficiently
//   and helps retrieve top K frequent words.
// =====================================================
class Trie {
private:
    TrieNode* root;

    // -------------------------------------------------
    // FUNCTION: insertUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Inserts a word into the Trie and updates
    //   its frequency at terminal node.
    // -------------------------------------------------
    void insertUtil(TrieNode* root,
                    const string& word,
                    int i) {

        // Base case: full word processed
        if (i >= word.size()) {
            root->isTerminal = true;
            ++root->freq;
            return;
        }

        int index = word[i] - 'a';

        // Create child if not present
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        // Recurse for next character
        insertUtil(root->children[index], word, i + 1);
    }

    // -------------------------------------------------
    // FUNCTION: traverseUtil
    // -------------------------------------------------
    // PURPOSE:
    //   DFS traversal of Trie to push words into
    //   min heap based on frequency and lex order.
    //
    // PARAMETERS:
    //   • root → current Trie node
    //   • s    → current word being formed
    //   • pq   → min heap storing top K words
    //   • k    → required number of words
    // -------------------------------------------------
    void traverseUtil(
        TrieNode* root,
        string& s,
        priority_queue<pair<int, string>,
        vector<pair<int, string>>, comp>& pq,
        int& k) {

        if (!root) return;

        // If a complete word is found
        if (root->isTerminal) {

            // If heap size < k → directly insert
            if (pq.size() < k) {
                pq.push({root->freq, s});
            }
            // Heap full → compare with top
            else if (pq.size() == k &&
                    (root->freq > pq.top().first ||
                    (root->freq == pq.top().first &&
                     s < pq.top().second))) {

                pq.pop();
                pq.push({root->freq, s});
            }
        }

        // DFS for all children
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                s.push_back(i + 'a');
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back();   // backtracking
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    // -------------------------------------------------
    // Insert word into Trie
    // -------------------------------------------------
    void insert(const string& word) {
        insertUtil(root, word, 0);
    }

    // -------------------------------------------------
    // Traverse Trie to fill min heap
    // -------------------------------------------------
    void traverse(priority_queue<pair<int, string>,
                  vector<pair<int, string>>, comp>& pq,
                  int& k) {

        string s;
        traverseUtil(root, s, pq, k);
    }
};

// =====================================================
// FUNCTION: topKFrequent
// -----------------------------------------------------
// PURPOSE:
//   Returns top K most frequent words.
//
// STRATEGY:
//   1️⃣ Insert all words into Trie
//   2️⃣ Traverse Trie and maintain min heap of size K
//   3️⃣ Extract heap contents into result
//
// TIME COMPLEXITY:
//   • O(N * L + W log K)
//     N = number of words
//     L = average word length
//     W = number of unique words
//
// SPACE COMPLEXITY:
//   • O(W * L)
// =====================================================
vector<string> topKFrequent(vector<string>& words, int k) {

    Trie trie;
    vector<string> ans;

    // Insert all words into Trie
    for (auto& word : words)
        trie.insert(word);

    // Min heap for top K words
    priority_queue<pair<int, string>,
        vector<pair<int, string>>, comp> pq;

    // Traverse Trie to fill heap
    trie.traverse(pq, k);

    // Extract words from heap
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // Reverse because min heap gives reverse order
    reverse(ans.begin(), ans.end());
    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        Input:
        words = ["i","love","leetcode","i","love","coding"]
        k = 2

        Frequencies:
        i → 2
        love → 2
        coding → 1
        leetcode → 1

        Output:
        ["i", "love"]
    */

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
