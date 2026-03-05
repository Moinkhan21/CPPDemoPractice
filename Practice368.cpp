#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a single node in the Trie data structure.
//
// PROPERTIES:
//   data        → character stored at node
//   children[]  → array of pointers for 26 lowercase letters
//   isTerminal  → marks end of a complete word
//
// WHY TRIE?
//   • Efficient prefix searching
//   • Used in autocomplete, dictionaries, search engines
//
// SPACE COMPLEXITY:
//   • Each node can have up to 26 children
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char d) {
        this->data = d;

        // Initialize all children as NULL
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        // Initially not a terminal node
        this->isTerminal = false;
    }
};

// =====================================================
// FUNCTION: insertWord
// -----------------------------------------------------
// PURPOSE:
//   Inserts a word into the Trie.
//
// APPROACH (RECURSIVE):
//   1️⃣ Take first character
//   2️⃣ Check if child exists
//   3️⃣ If not, create new node
//   4️⃣ Move to next character using recursion
//
// EXAMPLE:
//   insertWord(root, "love")
//
// TIME COMPLEXITY:
//   • O(L) where L = length of word
// =====================================================
void insertWord(TrieNode* root, string word) {

    // Base case: if word finished
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // -------------------------------------------------
    // CASE 1: Character already exists
    // -------------------------------------------------
    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // -------------------------------------------------
        // CASE 2: Character does not exist → create node
        // -------------------------------------------------
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursive call for remaining word
    insertWord(child, word.substr(1));
}

// =====================================================
// FUNCTION: searchWord
// -----------------------------------------------------
// PURPOSE:
//   Searches a word in the Trie.
//
// RETURN:
//   true  → word exists
//   false → word not found
//
// TIME COMPLEXITY:
//   • O(L)
// =====================================================
bool searchWord(TrieNode* root, string word) {

    // Base case
    if (word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // If character exists
    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }

    // Recursive search
    return searchWord(child, word.substr(1));
}

// =====================================================
// FUNCTION: storeSuggestions
// -----------------------------------------------------
// PURPOSE:
//   Stores all words in Trie that start with
//   the given prefix.
//
// HOW IT WORKS:
//   • DFS traversal of Trie
//   • If node is terminal → store word
//   • Explore children from 'a' to 'z'
//
// USED IN:
//   Autocomplete systems
// =====================================================
void storeSuggestions(TrieNode* curr, vector<string>& temp, string &prefix) {

    // If current node marks end of word
    if (curr->isTerminal)
        temp.push_back(prefix);

    // Explore all possible characters
    for (char ch = 'a'; ch <= 'z'; ch++) {

        int index = ch - 'a';

        TrieNode* next = curr->children[index];

        if (next != NULL) {

            // Add character to prefix
            prefix.push_back(ch);

            // Recursive DFS
            storeSuggestions(next, temp, prefix);

            // Backtracking
            prefix.pop_back();
        }
    }
}

// =====================================================
// FUNCTION: getSuggestions
// -----------------------------------------------------
// PURPOSE:
//   Returns autocomplete suggestions for each
//   prefix of the input string.
//
// EXAMPLE:
//   Words: love, lover, loving, last
//   Input: lovi
//
// OUTPUT:
//   l    → suggestions starting with l
//   lo   → suggestions starting with lo
//   lov  → suggestions starting with lov
//   lovi → suggestions starting with lovi
//
// TIME COMPLEXITY:
//   Depends on number of suggestions
// =====================================================
vector<vector<string>> getSuggestions(TrieNode* root, string input) {

    TrieNode* prev = root;

    vector<vector<string>> output;

    string prefix = "";

    for (int i = 0; i < input.length(); i++) {

        char lastCh = input[i];

        int index = lastCh - 'a';

        TrieNode* curr = prev->children[index];

        // If prefix does not exist
        if (curr == NULL)
            break;
        else {

            vector<string> temp;

            prefix.push_back(lastCh);

            // Store suggestions for current prefix
            storeSuggestions(curr, temp, prefix);

            output.push_back(temp);

            prev = curr;
        }
    }

    return output;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates Trie-based autocomplete system
// =====================================================
int main() {

    vector<string> v;

    // Dictionary words
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    // Create root node
    TrieNode* root = new TrieNode('-');

    // Insert words into Trie
    for (int i = 0; i < v.size(); i++) {
        insertWord(root, v[i]);
    }

    // Get suggestions
    vector<vector<string>> ans = getSuggestions(root, input);

    cout << "Printing the answer: " << endl;

    // Print suggestions
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}