#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a single node in the Trie.
//
// MEMBERS:
//   data        → character stored in node
//   children[]  → pointers to child nodes (26 letters)
//   isTerminal  → marks end of a word
//   childCount  → number of children (used for LCP logic)
//
// WHY childCount?
//   For Longest Common Prefix we check whether
//   a node has exactly one child. If yes, the
//   prefix continues; otherwise it stops.
//
// SPACE COMPLEXITY:
//   Each node can have up to 26 children.
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    // Constructor
    TrieNode(char d) {
        data = d;

        // Initialize children pointers
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
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
//   4️⃣ Move to next character recursively
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

    // Character already exists
    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // Create new node
        child = new TrieNode(ch);
        root->childCount++;
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
//   false → word does not exist
//
// TIME COMPLEXITY:
//   O(L)
// =====================================================
bool searchWord(TrieNode* root, string word) {

    // Base case
    if (word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';

    // If character path does not exist
    if (root->children[index] == NULL)
        return false;

    // Continue searching
    return searchWord(root->children[index], word.substr(1));
}

// =====================================================
// FUNCTION: findLCP
// -----------------------------------------------------
// PURPOSE:
//   Finds the Longest Common Prefix using Trie.
//
// IDEA:
//   • Traverse from root
//   • Continue while node has exactly ONE child
//   • Stop when:
//        - more than one child appears
//        - terminal node reached
//
// EXAMPLE:
//   flower
//   flow
//   flight
//
//   Trie path:
//   f → l → (branch)
//   LCP = "fl"
// =====================================================
void findLCP(string first, string& ans, TrieNode* root) {

    // If root itself is terminal, stop
    if (root->isTerminal)
        return;

    for (int i = 0; i < first.length(); i++) {

        char ch = first[i];

        // Continue only if single path exists
        if (root->childCount == 1) {

            ans.push_back(ch);

            int index = ch - 'a';
            root = root->children[index];
        }
        else {
            break;
        }

        // Stop if end of word reached
        if (root->isTerminal)
            break;
    }
}

// =====================================================
// FUNCTION: longestCommonPrefix
// -----------------------------------------------------
// PURPOSE:
//   Computes longest common prefix among strings.
//
// STEPS:
//   1️⃣ Insert all words into Trie
//   2️⃣ Traverse Trie using first word
//   3️⃣ Stop when branching occurs
//
// TIME COMPLEXITY:
//   O(N * L)
//
//   N → number of strings
//   L → average string length
// =====================================================
string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty())
        return "";

    // Create Trie root
    TrieNode* root = new TrieNode('-');

    // Insert all words
    for (int i = 0; i < strs.size(); i++) {
        insertWord(root, strs[i]);
    }

    string ans = "";
    string first = strs[0];

    // Compute LCP
    findLCP(first, ans, root);

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates Longest Common Prefix using Trie
// =====================================================
int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest Common Prefix: "
         << longestCommonPrefix(strs) << endl;

    return 0;
}