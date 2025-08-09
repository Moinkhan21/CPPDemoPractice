#include <iostream>    // For input/output
#include <string>      // For using strings
#include <vector>     // For using vectors
#include <map>        // For using maps
#include <algorithm>  // For sorting strings
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;

    for(auto str: strs) {
        string s = str;
        sort(s.begin(), s.end()); // Sort the string to find its anagram group
        mp[s].push_back(str); // Group the original string under its sorted version
    }
    
     vector<vector<string>> ans;
     for(auto it = mp.begin(); it != mp.end(); it++) {
         ans.push_back(it->second); // Collect all anagram groups
     }
    return ans; // Return the grouped anagrams
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    
    for(const auto& group : result) {
        for(const auto& str : group) {
            cout << str << " ";
        }
        cout << endl; // Print each group of anagrams
    }
    
    return 0;
}