#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
public:
    bool operator()(node a, node b) {
        return a.count < b.count;   // max heap
    }
};

string reorganizeString(string s) {

    // Frequency mapping
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch - 'a']++;
    }

    priority_queue<node, vector<node>, compare> maxHeap;

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            node temp(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    while (maxHeap.size() > 1) {

        node first = maxHeap.top();
        maxHeap.pop();

        node second = maxHeap.top();
        maxHeap.pop();

        ans += first.data;
        ans += second.data;

        first.count--;
        second.count--;

        if (first.count != 0) {
            maxHeap.push(first);
        }
        if (second.count != 0) {
            maxHeap.push(second);
        }
    }

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

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Input: "aaabbc"
        Output: "ababac" (one possible answer)
    */

    string s = "aaabbc";

    string result = reorganizeString(s);

    if (result == "")
        cout << "Reorganization not possible" << endl;
    else
        cout << "Reorganized string: " << result << endl;

    return 0;
}
