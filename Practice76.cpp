#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
using namespace std;

/*
    Function: getCharFrequency
    Purpose:  For a given string, count how many times each ASCII character appears.
    Logic:
        - We use a fixed-size array of length 256 (covering all ASCII characters).
        - Each index in the array represents an ASCII character.
        - freq[c] stores how many times character 'c' appears in the string.
*/
array<int, 256> getCharFrequency(const string& s) {
    array<int, 256> freq = {0}; // Initialize all 256 counts to 0
    for (char c : s) {
        freq[(unsigned char)c]++; // Increase count for character 'c'
    }
    return freq; // Return frequency array as "signature" of the string
}

/*
    Function: groupAnagrams
    Purpose:  Group words that are anagrams of each other.
    Logic:
        - Two strings are anagrams if they have the same frequency of each character.
        - Example: "eat" and "tea" -> both have (a=1, e=1, t=1).
        - We use a map where:
              Key   = frequency array of characters (signature of word).
              Value = vector of words having the same signature.
        - Finally, collect all groups from the map and return them.
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Map each frequency array to a list of words
    map<array<int, 256>, vector<string>> mp;

    // For each string, calculate its frequency array and insert into map
    for (const auto& str : strs) {
        mp[getCharFrequency(str)].push_back(str);
    }

    // Collect results into a vector of vectors
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second); // Take only the list of words (values)
    }
    return ans;
}

int main() {
    // Input list of words
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Group the words into anagrams
    vector<vector<string>> result = groupAnagrams(strs);

    // Print each group of anagrams
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " "; // Print word
        }
        cout << endl; // New line after each group
    }

    return 0;
}
