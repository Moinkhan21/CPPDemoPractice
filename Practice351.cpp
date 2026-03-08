#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// =====================================================
// CLASS: node
// -----------------------------------------------------
// PURPOSE:
//   Represents a character and its frequency.
//
// MEMBERS:
//   data  → character
//   count → frequency of character
// =====================================================
class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

// =====================================================
// CLASS: compare
// -----------------------------------------------------
// PURPOSE:
//   Custom comparator for priority_queue.
//
// FUNCTIONALITY:
//   Creates a MAX HEAP based on character frequency.
//
// WHY?
//   We always want to pick the characters with the
//   highest remaining frequency first.
// =====================================================
class compare {
public:
    bool operator()(node a, node b) {
        return a.count < b.count;   // Max heap
    }
};

// =====================================================
// FUNCTION: reorganizeString
// -----------------------------------------------------
// PROBLEM:
//   Rearrange the characters of the string so that
//   no two adjacent characters are the same.
//
// EXAMPLE:
//   Input:  "aaabbc"
//   Output: "ababac"
//
// APPROACH (GREEDY + MAX HEAP):
//
//   1️⃣ Count frequency of all characters.
//
//   2️⃣ Push characters with frequencies into a
//      max heap.
//
//   3️⃣ At each step:
//       - Take two most frequent characters
//       - Append them to result
//       - Decrease their frequency
//
//   4️⃣ If frequency remains → push back into heap.
//
//   5️⃣ If one character remains:
//        - If count == 1 → append
//        - Else → impossible
//
// WHY THIS WORKS?
//   Taking the two highest frequency characters
//   ensures that no identical characters become
//   adjacent.
//
// TIME COMPLEXITY:
//   O(n log k)
//
//   n → length of string
//   k → number of distinct characters
//
// SPACE COMPLEXITY:
//   O(k)
// =====================================================
string reorganizeString(string s) {

    // -------------------------------------------------
    // STEP 1: Frequency Mapping
    // -------------------------------------------------
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch - 'a']++;
    }

    // -------------------------------------------------
    // STEP 2: Create Max Heap
    // -------------------------------------------------
    priority_queue<node, vector<node>, compare> maxHeap;

    for (int i = 0; i < 26; i++) {

        if (freq[i] != 0) {

            node temp(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    // -------------------------------------------------
    // STEP 3: Process two most frequent characters
    // -------------------------------------------------
    while (maxHeap.size() > 1) {

        node first = maxHeap.top();
        maxHeap.pop();

        node second = maxHeap.top();
        maxHeap.pop();

        // Add characters to result
        ans += first.data;
        ans += second.data;

        // Decrease frequencies
        first.count--;
        second.count--;

        // Push back if still remaining
        if (first.count != 0) {
            maxHeap.push(first);
        }

        if (second.count != 0) {
            maxHeap.push(second);
        }
    }

    // -------------------------------------------------
    // STEP 4: Handle last remaining character
    // -------------------------------------------------
    if (maxHeap.size() == 1) {

        node temp = maxHeap.top();
        maxHeap.pop();

        if (temp.count == 1)
            ans += temp.data;
        else
            return "";
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates reorganizing a string so that
//   no two adjacent characters are the same.
// =====================================================
int main() {

    /*
        Input:
        "aaabbc"

        Possible Output:
        "ababac"
    */

    string s = "aaabbc";

    string result = reorganizeString(s);

    if (result == "")
        cout << "Reorganization not possible" << endl;
    else
        cout << "Reorganized string: " << result << endl;

    return 0;
}