#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a node in the Trie.
//
// DATA MEMBERS:
//   • data        → character stored at this node
//   • children[26]→ pointers to next characters (a–z)
//   • isTerminal  → true if a root word ends here
//
// NOTE:
//   Each path from root to terminal node represents
//   a valid dictionary root word.
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
// -----------------------------------------------------
// PURPOSE:
//   Stores dictionary root words and allows
//   efficient prefix search.
//
// KEY IDEA:
//   • Instead of checking all roots for each word,
//     we use Trie to match prefixes efficiently.
// =====================================================
class Trie {
private:
    TrieNode* root;

    // -------------------------------------------------
    // FUNCTION: insertUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Inserts a word into the Trie recursively.
    //
    // PARAMETERS:
    //   • root → current Trie node
    //   • word → root word to insert
    //   • i    → current index in word
    //
    // TIME COMPLEXITY:
    //   • O(L), where L = length of word
    // -------------------------------------------------
    void insertUtil(TrieNode* root,
                    const string& word,
                    int i) {

        // Base case: word completely inserted
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';

        // Create node if not present
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        // Recursive insertion
        insertUtil(root->children[index],
                   word,
                   i + 1);
    }

    // -------------------------------------------------
    // FUNCTION: searchUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Finds the shortest root word that matches
    //   the prefix of given word.
    //
    // RETURNS:
    //   • Index where root ends
    //   • -1 if no root matches
    //
    // KEY POINT:
    //   Stop as soon as a terminal node is found
    //   (shortest root rule)
    // -------------------------------------------------
    int searchUtil(TrieNode* root,
                   const string& word,
                   int i) {

        // If root word ends here → match found
        if (root->isTerminal)
            return i;

        // If full word traversed but no root found
        if (i >= word.size())
            return -1;

        int index = word[i] - 'a';

        // Continue traversal if path exists
        if (root->children[index])
            return searchUtil(root->children[index],
                              word,
                              i + 1);

        // No matching path
        return -1;
    }

    // -------------------------------------------------
    // FUNCTION: startWithUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Checks if any word in Trie starts with prefix
    //
    // (Not used in main solution but useful utility)
    // -------------------------------------------------
    bool startWithUtil(TrieNode* root,
                       const string& word,
                       int i) {

        if (i >= word.size())
            return true;

        int index = word[i] - 'a';

        if (root->children[index])
            return startWithUtil(root->children[index],
                                 word,
                                 i + 1);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    // -------------------------------------------------
    // Insert a word into Trie
    // -------------------------------------------------
    void insert(const string& word) {
        insertUtil(root, word, 0);
    }

    // -------------------------------------------------
    // Search shortest root prefix
    // -------------------------------------------------
    int search(const string& word) {
        return searchUtil(root, word, 0);
    }

    // -------------------------------------------------
    // Prefix check
    // -------------------------------------------------
    bool startWith(const string& prefix) {
        return startWithUtil(root, prefix, 0);
    }
};

// =====================================================
// FUNCTION: replaceWords
// -----------------------------------------------------
// PURPOSE:
//   Replace words in sentence with shortest root
//   from dictionary.
//
// PROBLEM:
//   Given dictionary of root words and a sentence,
//   replace each word with its shortest root prefix.
//
// APPROACH:
//   1️⃣ Insert all dictionary roots into Trie
//   2️⃣ Traverse sentence word by word
//   3️⃣ For each word:
//       • Find root using Trie
//       • Replace if found
//
// TIME COMPLEXITY:
//   • O(N × L)
//     N = number of words
//     L = average word length
// =====================================================
string replaceWords(vector<string>& dictionary,
                    string sentence) {

    string ans;
    Trie trie;

    // -------------------------------------------------
    // STEP 1: Insert dictionary roots into Trie
    // -------------------------------------------------
    for (auto& root : dictionary)
        trie.insert(root);

    int start = 0;
    int end = 0;

    // -------------------------------------------------
    // STEP 2: Parse sentence word by word
    // -------------------------------------------------
    while (end < sentence.size()) {

        // When space OR last character reached
        if (sentence[end] == ' ' ||
            end == sentence.size() - 1) {

            // Calculate word length
            int len = (end == sentence.size() - 1)
                        ? sentence.size() - start
                        : end - start;

            // Extract current word
            string word = sentence.substr(start, len);

            // -------------------------------------------------
            // STEP 3: Search for root
            // -------------------------------------------------
            int trieMatchIndex = trie.search(word);

            // Replace with root if found
            if (trieMatchIndex != -1)
                ans += word.substr(0, trieMatchIndex);
            else
                ans += word;

            // Add space if needed
            if (sentence[end] == ' ')
                ans += " ";

            // Move to next word
            start = end + 1;
        }

        ++end;
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    /*
        Dictionary:
        ["cat", "bat", "rat"]

        Sentence:
        "the cattle was rattled by the battery"

        Output:
        "the cat was rat by the bat"
    */

    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << replaceWords(dictionary, sentence) << endl;

    return 0;
}
