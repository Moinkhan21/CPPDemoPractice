#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ====================================================================
// ✅ FUNCTION: celebrity()
// --------------------------------------------------------------------
// Purpose:
//   Determines if there is a **celebrity** in a group of people using
//   the "knows" relationship matrix `M`.
//
// Definition of Celebrity:
//   1️⃣ A celebrity **knows no one** (their entire row = 0).
//   2️⃣ Everyone **knows the celebrity** (their entire column = 1, except diagonal).
//
// Parameters:
//   - M: 2D vector representing relationships.
//     M[a][b] == 1 → person 'a' knows person 'b'.
//     M[a][b] == 0 → person 'a' does NOT know person 'b'.
//   - n: total number of people.
// --------------------------------------------------------------------
// Approach (Stack-based):
//   1️⃣ Push all people (0...n-1) into a stack.
//   2️⃣ Compare two persons at a time to eliminate non-celebrities:
//       - If A knows B → A is not a celebrity.
//       - Else → B is not a celebrity.
//   3️⃣ Verify the remaining candidate by checking both celebrity rules.
// --------------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ====================================================================
int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;

    // ✅ Step 1: Push all people (0, 1, 2, ..., n-1) into stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // ✅ Step 2: Find a potential celebrity by pairwise elimination
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        // If person 'a' knows 'b', 'a' cannot be a celebrity
        if (M[a][b] == 1) {
            st.push(b);
        }
        else {
            // If 'a' does NOT know 'b', 'b' cannot be a celebrity
            st.push(a);
        }
    }

    // After elimination, one person might be a celebrity
    int mightBeCelebrity = st.top();

    // ✅ Step 3: Verify if this candidate is a real celebrity

    // (a) Celebrity must not know anyone
    for (int i = 0; i < n; i++) {
        if (M[mightBeCelebrity][i] != 0) {
            return -1; // Knows someone → Not a celebrity
        }
    }

    // (b) Everyone else must know the celebrity
    for (int i = 0; i < n; i++) {
        if (i != mightBeCelebrity && M[i][mightBeCelebrity] != 1) {
            return -1; // Someone doesn't know the celebrity → Not valid
        }
    }

    return mightBeCelebrity; // ✅ Valid celebrity found
}

// ====================================================================
// ✅ MAIN FUNCTION — Test the celebrity finder
// --------------------------------------------------------------------
// Matrix M represents the following relationships:
//   M[a][b] == 1 → person 'a' knows 'b'
//   M[a][b] == 0 → person 'a' does not know 'b'
// ====================================================================
int main() {
    // Example: 3 people (0, 1, 2)
    // Person 2 does not know anyone, and everyone knows person 2 → Celebrity!
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}  // ✅ Candidate — knows no one
    };

    int n = 3;
    int result = celebrity(M, n);

    // ✅ Output Result
    if (result == -1)
        cout << "No celebrity exists." << endl;
    else
        cout << "Celebrity Index: " << result << endl;

    return 0;
}
