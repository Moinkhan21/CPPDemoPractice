#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// =======================================================
// ✅ Function: prevSmallerElement()
// -------------------------------------------------------
// Purpose:
//   For each element in the array, find the **previous smaller element**
//   (i.e., the first smaller element to its left).
//
// Approach:
//   - Use a stack to keep track of potential smaller elements.
//   - For each element (from left → right):
//       1️⃣ Pop elements from stack until a smaller one is found.
//       2️⃣ If stack is empty, no smaller element → store -1.
//       3️⃣ Otherwise, top of stack = previous smaller element.
//       4️⃣ Push current element onto the stack.
// =======================================================
vector<int> prevSmallerElement(vector<int>& input) {
    stack<int> s;     // Stack to store potential smaller elements
    s.push(-1);       // Sentinel value (for no smaller element found)

    vector<int> ans(input.size()); // Stores previous smaller elements

    // Traverse from left to right
    for(int i = 0; i < input.size(); i++) {
        int curr = input[i];  // Current element

        // Pop all elements greater than or equal to current
        while(s.top() >= curr) {
            s.pop();
        }

        // Top of stack is the previous smaller element
        ans[i] = s.top();

        // Push current element for future comparisons
        s.push(curr);
    }
    return ans;
}

// =======================================================
// ✅ Function: nextSmallerElement()
// -------------------------------------------------------
// Purpose:
//   For each element in the array, find the **next smaller element**
//   (i.e., the first smaller element to its right).
//
// Approach:
//   - Traverse array from right → left.
//   - Maintain a stack of elements for which we haven’t found a smaller element yet.
//   - Pop until a smaller element is found.
// =======================================================
vector<int> nextSmallerElement(vector<int> &input) {
    stack<int> s;     // Stack to store elements
    s.push(-1);       // Sentinel for no smaller element
    vector<int> ans(input.size());

    // Traverse from right to left
    for(int i = input.size() - 1; i >= 0; i--) {
        int curr = input[i];

        // Remove elements that are not smaller than current
        while(s.top() >= curr) {
            s.pop();
        }

        // Top of stack is the next smaller element
        ans[i] = s.top();

        // Push current element for next iteration
        s.push(curr);
    }
    return ans;
}

// =======================================================
// ✅ Main Function — Demonstrates Previous & Next Smaller Elements
// =======================================================
int main() {
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    // Find next smaller elements for each input element
    vector<int> ans1 = nextSmallerElement(input);
    cout << "Next Smaller Elements:" << endl;
    for(int i = 0; i < input.size(); i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    // Find previous smaller elements for each input element
    vector<int> ans2 = prevSmallerElement(input);
    cout << "Previous Smaller Elements:" << endl;
    for(int i = 0; i < input.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}
