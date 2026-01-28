#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty()) return "";

    string ans = "";

    // Loop on first string
    for (int i = 0; i < strs[0].length(); i++) {

        char ch = strs[0][i];
        bool match = true;

        // Compare with remaining strings
        for (int j = 1; j < strs.size(); j++) {
            //Compare
            if (i >= strs[j].size() || ch != strs[j][i]) {
                match = false;
                break;
            }

            //Or
            //Compare
            // if(strs[j].size() < i || ch != strs[j][i]) {
            //     match = false;
            //     break;
            // }
        }

        if (!match)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest Common Prefix: "
         << longestCommonPrefix(strs) << endl;

    return 0;
}
