#include <iostream>   // For input-output operations (cout, cin)
#include <string>     // For using the string class
#include <limits.h>   // For INT_MAX and INT_MIN constants
using namespace std;

/*
    Function: myAtoi
    Purpose: Converts a given string to an integer (mimicking the C `atoi` function)
             Handles leading spaces, optional '+' or '-' signs, ignores invalid trailing characters,
             and manages integer overflow/underflow.
    Parameters:
        - s: The input string to convert
    Returns:
        - The integer representation of the string (with overflow and underflow handled)
*/
int myAtoi(string s) {
    int num = 0;        // Stores the final integer value being formed
    int i = 0;          // Index pointer to traverse the string
    int sign = 1;       // Sign of the number (1 for positive, -1 for negative by default positive)

    // Step 1: Skip any leading spaces
    // Continue moving the index forward until a non-space character is found
    while (i < s.size() && s[i] == ' ') {
        i++;
    }

    // Step 2: Check for optional sign (+ or -)
    // If a '+' is found, sign remains positive
    // If a '-' is found, sign becomes negative
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '+') ? 1 : -1; // Conditional assignment of sign
        i++; // Move to the next character after sign
    }

    // Step 3: Process numerical digits until a non-digit is found
    while (i < s.size() && isdigit(s[i])) {
        // Step 3.1: Handle potential overflow before multiplying and adding
        // If num is already greater than INT_MAX/10, adding any digit will overflow
        // If num == INT_MAX/10, we must ensure the next digit does not exceed the limit
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            // If positive number overflows, return INT_MAX
            // If negative number overflows, return INT_MIN
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // Step 3.2: Convert character digit to integer and append to num
        // 's[i] - '0'' converts ASCII digit character to its numeric value
        num = num * 10 + (s[i] - '0');

        // Move to next character
        i++;
    }

    // Step 4: Apply sign and return result
    return num * sign;
}

int main() {
    string str = "   -42";  // Test string with leading spaces and negative sign
    int result = myAtoi(str);  // Convert string to integer
    cout << result << endl;    // Output: -42
    return 0;
}
