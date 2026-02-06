#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// =====================================================
// CLASS: TrieNode
// -----------------------------------------------------
// PURPOSE:
//   Represents a single node in the Trie.
//
// DATA MEMBERS:
//   • data          → character stored at this node
//   • children[26]  → pointers to next characters
//   • stringNumber  → index of word ending here
//   • isTerminal    → marks end of a word
//
// IMPORTANT NOTE:
//   stringNumber = -1 means no word ends here
// =====================================================
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int stringNumber;
    bool isTerminal;

    TrieNode(char ch)
        : data(ch), stringNumber(-1), isTerminal(false) {

        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// =====================================================
// CLASS: Trie
// -----------------------------------------------------
// PURPOSE:
//   Stores reversed words to efficiently find
//   palindrome pairs.
//
// WHY REVERSED WORDS?
//   • To match suffix of a word with prefix of another
//   • Key trick for palindrome pair problems
// =====================================================
class Trie {
    TrieNode* root;

    // -------------------------------------------------
    // FUNCTION: insertUtil
    // -------------------------------------------------
    // PURPOSE:
    //   Inserts a word into the Trie recursively.
    //
    // PARAMETERS:
    //   • root         → current Trie node
    //   • word         → string being inserted
    //   • i            → current index in word
    //   • stringNumber → index of word in input array
    // -------------------------------------------------
    void insertUtil(TrieNode* root,
                    string& word,
                    int i,
                    int& stringNumber) {

        // Base case: word completely inserted
        if (i >= word.size()) {
            root->stringNumber = stringNumber;
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';

        // Create child if not present
        if (!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        // Recurse for next character
        insertUtil(root->children[index],
                   word,
                   i + 1,
                   stringNumber);
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    // -------------------------------------------------
    // FUNCTION: insert
    // -------------------------------------------------
    // PURPOSE:
    //   Public wrapper for inserting a word into Trie
    // -------------------------------------------------
    void insert(string& word, int& stringNumber) {
        insertUtil(root, word, 0, stringNumber);
    }

    // -------------------------------------------------
    // FUNCTION: isPalindrome
    // -------------------------------------------------
    // PURPOSE:
    //   Checks if substring s[low...high] is palindrome
    // -------------------------------------------------
    bool isPalindrome(string& s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    // -------------------------------------------------
    // FUNCTION: searchCase2
    // -------------------------------------------------
    // PURPOSE (CASE 2):
    //   When input word is fully matched in Trie,
    //   check remaining Trie paths for palindromes.
    //
    // EXAMPLE:
    //   word = "lls"
    //   matching path = "ll"
    //   remaining = "s"
    // -------------------------------------------------
    void searchCase2(TrieNode* node,
                     vector<int>& myPalindrome,
                     string s) {

        // If a word ends here and remaining is palindrome
        if (node->stringNumber != -1) {
            if (isPalindrome(s, 0, s.size() - 1))
                myPalindrome.push_back(node->stringNumber);
        }

        // DFS through all children
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                s.push_back(i + 'a');
                searchCase2(node->children[i],
                            myPalindrome,
                            s);
                s.pop_back(); // backtrack
            }
        }
    }

    // -------------------------------------------------
    // FUNCTION: search
    // -------------------------------------------------
    // PURPOSE:
    //   Searches for palindrome pairs for a given word.
    //
    // TWO CASES:
    //   Case 1️⃣: Remaining part of word is palindrome
    //   Case 2️⃣: Remaining Trie path is palindrome
    // -------------------------------------------------
    void search(string& word, vector<int>& myPalindrome) {

        TrieNode* curr = root;

        // ===============================
        // CASE 1: While traversing word
        // ===============================
        for (int i = 0; i < word.size(); ++i) {

            // If a word ends here in Trie
            if (curr->stringNumber != -1) {
                if (isPalindrome(word,
                                 i,
                                 word.size() - 1))
                    myPalindrome.push_back(curr->stringNumber);
            }

            int index = word[i] - 'a';

            // No matching path → stop
            if (!curr->children[index])
                return;

            curr = curr->children[index];
        }

        // ===============================
        // CASE 2: Word exhausted
        // ===============================
        searchCase2(curr, myPalindrome, "");
    }
};

// =====================================================
// FUNCTION: palindromePairs
// -----------------------------------------------------
// PURPOSE:
//   Finds all pairs (i, j) such that:
//
//     words[i] + words[j] is a palindrome
//
// STRATEGY:
//   1️⃣ Insert REVERSED words into Trie
//   2️⃣ Search each original word in Trie
//   3️⃣ Apply Case 1 & Case 2 logic
//
// TIME COMPLEXITY:
//   • O(N * L²)
//     N = number of words
//     L = average word length
// =====================================================
vector<vector<int>> palindromePairs(vector<string>& words) {

    vector<vector<int>> ans;
    Trie trie;

    // Insert reversed words
    for (int i = 0; i < words.size(); ++i) {
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        trie.insert(rev, i);
    }

    // Search palindrome pairs
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

// =====================================================
// MAIN FUNCTION (TEST CASE)
// =====================================================
int main() {

    /*
        Input:
        ["abcd", "dcba", "lls", "s", "sssll"]

        Output:
        [0,1], [1,0], [3,2], [2,4]
    */

    vector<string> words =
        {"abcd", "dcba", "lls", "s", "sssll"};

    vector<vector<int>> result =
        palindromePairs(words);

    cout << "Palindrome Pairs:\n";
    for (auto& p : result) {
        cout << "[" << p[0] << ", "
             << p[1] << "]\n";
    }

    return 0;
}
