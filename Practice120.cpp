#include <iostream>     // For standard input/output (cin, cout)
#include <string>       // For using std::string
#include <algorithm>    // For reverse() function
using namespace std;

/*
 Function: addRE
 ----------------
 This function recursively adds two numbers represented as strings.

 Parameters:
 - num1, p1 : first number and its current index (starting from the last digit)
 - num2, p2 : second number and its current index (starting from the last digit)
 - carry    : carry value from the previous addition
 - ans      : reference to result string that stores the sum (built in reverse order)

 Steps:
 1. Base case: If both strings are exhausted and no carry remains, stop recursion.
 2. Solve one case: Take digits from num1 and num2 at current positions, add them with carry.
 3. Store the last digit of sum in result string.
 4. Pass the remaining part to recursive call.
*/
void addRE(string &num1, int p1, string &num2, int p2, int carry, string &ans) {

    // ✅ Base case:
    if(p1 < 0 && p2 < 0){
        // If we still have a carry left, push it as the last digit
        if(carry != 0){
            ans.push_back(carry + '0'); // convert int → char
        }
        return; // End recursion
    }

    // ✅ Solve one case:
    // Get current digits (if index < 0, use '0')
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';  // digit from num1
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';  // digit from num2

    // Calculate sum with carry
    int csum = n1 + n2 + carry;

    // Extract digit to store and update carry
    int digit = csum % 10;     // last digit of sum
    carry = csum / 10;         // remaining carry

    // Store digit in result (as char)
    ans.push_back(digit + '0');

    // ✅ Recursive call: move to next digit (left side)
    addRE(num1, p1 - 1, num2, p2 - 1, carry, ans);
}

/*
 Function: addstrings
 --------------------
 Wrapper function that calls recursive addRE function.

 Steps:
 1. Call recursive function starting from last index of both strings.
 2. Reverse the result because we built it backwards.
 3. Return final answer.
*/
string addstrings(string num1, string num2) {
    string ans = "";

    // Start recursion from last index of both numbers
    addRE(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);

    // Reverse result (because we inserted digits from least significant to most significant)
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Input two numbers as strings (to handle very large numbers beyond int/long long range)
    string str1;
    cout << "Enter first string: ";
    cin >> str1;

    string str2;
    cout << "Enter second string: ";
    cin >> str2;

    // Call the add function
    string result = addstrings(str1, str2);

    // Output result
    cout << "Result is: " << result << endl;

    return 0;
}
