#include <iostream>    // For input/output
#include <string>      // For using strings
#include <climits>    // For INT_MIN
using namespace std;

string reorganizeString(string s){

    int hash[26] = {0}; // Frequency array for characters 'a' to 'z'

    for(int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++; // Count frequency of each character
    }//O(n)

    // Find the most frequent character
    char max_freq_char;
    int max_freq = INT_MIN;
    for(int i = 0; i < 26; i++) {
        if(hash[i] > max_freq) {
            max_freq = hash[i];
            max_freq_char = i + 'a'; // Convert index back to character
        }
    }

    int index = 0;
    while(max_freq > 0 && index < s.size()) {
        s[index] = max_freq_char; // Place the most frequent character
        max_freq--;
        index += 2; // Skip to the next even index
    }// O(n)

    if(max_freq != 0) {
        return ""; // If we still have characters left, return empty string
    }

    hash[max_freq_char - 'a'] = 0; // Set frequency of the most frequent character to 0

    //Let's place the rest of the characters
    for(int i = 0; i < 26; i++){
        while(hash[i] > 0) {
            index = (index >= s.size()) ? 1 : index; // If we reach the end, start filling odd indices
            s[index] = i + 'a'; // Place the character
            hash[i]--; // Decrease frequency
            index += 2; // Move to the next index
        }
    } //O(n)

    return s; // Return the reorganized string
}

int main() {
    string s = "aabb";
    string result = reorganizeString(s);
    if(result.empty()) {
        cout << "Cannot reorganize the string." << endl;
    } else {
        cout << "Reorganized string: " << result << endl;
    }
    return 0;
}