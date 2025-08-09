#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
using namespace std;

// Function to get frequency of each ASCII character
array<int, 256> getCharFrequency(const string& s) {
    array<int, 256> freq = {0}; // Initialize all counts to 0
    for (char c : s) {
        freq[(unsigned char)c]++; // Count character frequency
    }
    return freq;
}

// Function to group anagrams together
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<array<int, 256>, vector<string>> mp;

    for (const auto& str : strs) {
        mp[getCharFrequency(str)].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second); // Only store the vector of strings
    }
    return ans;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl; // New line after each group
    }

    return 0;
}
