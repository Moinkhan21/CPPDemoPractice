#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a node in the Trie used for
//   CamelCase pattern matching.
//
// DATA MEMBERS:
//   • data         → character stored in the node
//   • children[58] → pointers for characters from
//                    'A' (65) to 'z' (122)
//   • isTerminal   → marks end of the pattern
//
// WHY SIZE = 58?
//   'z' - 'A' + 1 = 122 - 65 + 1 = 58
//   This range covers:
//     • Uppercase letters
//     • Lowercase letters
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
// -----------------------------------------------------
// PURPOSE:
//   Stores the CamelCase PATTERN and checks whether
//   a query string matches the pattern.
//
// KEY IDEA:
//   • Uppercase letters in query MUST match pattern
//   • Lowercase letters in query can be ignored
// =====================================================
class Trie {
private:
    TrieNode* root;

    // =================================================
    // FUNCTION: insertUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Inserts the pattern string into the Trie.
    //
    // PARAMETERS:
    //   • root → current Trie node
    //   • word → pattern string
    //   • i    → current index in pattern
    //
    // TIME COMPLEXITY:
    //   • O(length of pattern)
    // =================================================
    void insertUtil(TrieNode* root, string& word, int i) {

        // Base case: full pattern inserted
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        // Map character to index
        int index = word[i] - 'A';

        // Create child if not present
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        // Recurse for next character
        insertUtil(root->children[index], word, i + 1);
    }

    // =================================================
    // FUNCTION: searchUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Checks whether a query matches the CamelCase
    //   pattern stored in the Trie.
    //
    // RULES:
    //   • Uppercase letter MUST match Trie path
    //   • Lowercase letter can be skipped
    //
    // RETURNS:
    //   • true  → query matches pattern
    //   • false → query does NOT match pattern
    //
    // TIME COMPLEXITY:
    //   • O(length of query)
    // =================================================
    int searchUtil(TrieNode* root, string& word, int i) {

        // If query fully processed
        if (i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'A';

        // Case 1: Character matches Trie path
        if (root->children[index])
            return searchUtil(root->children[index],
                              word,
                              i + 1);

        // Case 2: Lowercase character → skip it
        else if (islower(word[i]))
            return searchUtil(root,
                              word,
                              i + 1);

        // Case 3: Uppercase mismatch → invalid
        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    // -------------------------------------------------
    // Insert pattern into Trie
    // -------------------------------------------------
    void insert(string& word) {
        insertUtil(root, word, 0);
    }

    // -------------------------------------------------
    // Search query in Trie
    // -------------------------------------------------
    bool search(string& word) {
        return searchUtil(root, word, 0);
    }
};

// =====================================================
// FUNCTION: camelMatch
// -----------------------------------------------------
// PURPOSE:
//   For each query, check whether it matches
//   the given CamelCase pattern.
//
// INPUT:
//   • queries → list of strings
//   • pattern → CamelCase pattern
//
// OUTPUT:
//   • vector<bool> where true means match
//
// STRATEGY:
//   1️⃣ Insert pattern into Trie
//   2️⃣ Search each query using Trie rules
//
// TIME COMPLEXITY:
//   • O(Q × L)
//     Q = number of queries
//     L = average query length
// =====================================================
vector<bool> camelMatch(vector<string>& queries,
                         string pattern) {

    vector<bool> ans;
    Trie trie;

    // Insert pattern into Trie
    trie.insert(pattern);

    // Check each query
    for (auto& query : queries) {
        ans.push_back(trie.search(query));
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        Queries:
        ["FooBar", "FooBarTest", "FootBall",
         "FrameBuffer", "ForceFeedBack"]

        Pattern:
        "FB"

        Output:
        true false true true false
    */

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
