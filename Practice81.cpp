#include <iostream>
#include <string>
using namespace std;

/*
 * Function: intToRoman
 * ---------------------
 * Converts an integer into its Roman numeral representation.
 * 
 * Parameters:
 *   num - The integer to be converted (must be between 1 and 3999 for valid Roman numerals).
 * 
 * Returns:
 *   A string containing the Roman numeral equivalent of the given integer.
 */
string intToRoman(int num) {
    // This will store the final Roman numeral string
    string result = "";

    /*
     * Roman numerals and their corresponding integer values.
     * We list them in descending order so we can greedily subtract
     * the largest possible value at each step.
     */
    string romanNumerals[] = { "M",  "CM", "D",  "CD", "C",  "XC", 
                                "L",  "XL", "X",  "IX", "V",  "IV", "I" };
    int values[]            = {1000, 900, 500, 400, 100,  90, 
                                 50,   40,  10,    9,   5,    4,   1};

    // Loop through each numeral-value pair
    for (int i = 0; i < 13; i++) {
        /*
         * While the current value can still be subtracted from num,
         * append its Roman numeral to the result string and reduce num.
         * Example: num = 1994 → First subtract 1000 ("M"), then 900 ("CM"), etc.
         */
        while (num >= values[i]) {
            result += romanNumerals[i]; // Append Roman symbol
            num -= values[i];           // Reduce the number
        }
    }

    // Return the fully constructed Roman numeral string
    return result;
}

int main() {
    int num = 1994; // Example input number

    // Convert integer to Roman numeral
    string roman = intToRoman(num);

    // Output the result
    cout << "The Roman numeral for " << num << " is " << roman << endl;

    return 0; // Indicate successful execution
}
