#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// =======================================================
// FUNCTION: celebrity
// Returns index of celebrity (0-based), or -1 if none exists
// =======================================================
int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;

    // Step 1: Push all people into stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Determine the "possible" celebrity
    while (st.size() != 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        // If 'a' knows 'b', then 'a' cannot be celebrity
        if (M[a][b] == 1) {
            st.push(b);
        }
        else {
            // If 'a' does not know 'b', then 'b' cannot be celebrity
            st.push(a);
        }
    }

    // Step 3: Verify if the remaining candidate is a real celebrity
    int mightBeCelebrity = st.top();

    // (a) Celebrity knows no one
    for (int i = 0; i < n; i++) {
        if (M[mightBeCelebrity][i] != 0) {
            return -1;
        }
    }

    // (b) Everyone must know celebrity
    for (int i = 0; i < n; i++) {
        if (i != mightBeCelebrity && M[i][mightBeCelebrity] != 1) {
            return -1;
        }
    }

    return mightBeCelebrity;  // Valid celebrity
}

// =======================================================
// MAIN: Test the celebrity finder
// =======================================================
int main() {
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}     // Person 2 knows nobody → candidate
    };

    int n = 3;
    int result = celebrity(M, n);

    if (result == -1)
        cout << "No celebrity exists." << endl;
    else
        cout << "Celebrity Index: " << result << endl;

    return 0;
}
