#include <iostream>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a node in the Trie data structure.
//
// MEMBERS:
//   data        → character stored in node
//   children[]  → pointers to child nodes (26 letters)
//   isTerminal  → true if node represents end of a word
//
// WHY TRIE?
//   • Fast prefix searching
//   • Used in dictionaries, autocomplete, spell check
//
// SPACE COMPLEXITY:
//   Each node may have up to 26 children.
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

        // Initially node is not terminal
        this->isTerminal = false;
    }
};

// =====================================================
// FUNCTION: insertWord
// -----------------------------------------------------
// PURPOSE:
//   Inserts a word into the Trie.
//
// APPROACH (Recursive):
//   1️⃣ Take first character
//   2️⃣ Check if node already exists
//   3️⃣ If not, create new node
//   4️⃣ Recursively insert remaining characters
//
// EXAMPLE:
//   insertWord(root, "code")
//
// TIME COMPLEXITY:
//   O(L) where L = length of word
// =====================================================
void insertWord(TrieNode* root, string word) {

    // Base case → word finished
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
        // CASE 2: Character not present → create new node
        // -------------------------------------------------
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursively insert remaining characters
    insertWord(child, word.substr(1));
}

// =====================================================
// FUNCTION: searchWord
// -----------------------------------------------------
// PURPOSE:
//   Searches whether a word exists in the Trie.
//
// RETURN:
//   true  → word present
//   false → word not present
//
// TIME COMPLEXITY:
//   O(L)
// =====================================================
bool searchWord(TrieNode* root, string word) {

    // Base case → end of word reached
    if (word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // If character exists in Trie
    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }

    // Recursive search for remaining characters
    return searchWord(child, word.substr(1));  // IMPORTANT: return added
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates insertion and searching in Trie
// =====================================================
int main() {

    // Create root node
    TrieNode* root = new TrieNode('-');

    // Insert words into Trie
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");

    // Search word
    if (searchWord(root, "coding")) {
        cout << "present" << endl;
    }
    else {
        cout << "absent" << endl;
    }

    return 0;
}