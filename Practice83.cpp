#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>       // For using std::string
#include <vector>       // For using std::vector
#include <algorithm>    // For using std::sort

using namespace std;

/*
    Custom comparator function for sorting strings in the desired order.

    Given two strings `a` and `b` (representing numbers), we compare:
        - t1 = a + b
        - t2 = b + a
    Example:
        a = "9", b = "34"
        t1 = "934", t2 = "349"
        Since "934" > "349", `a` should come before `b` in sorting.

    We return true if t1 > t2 because we want the largest number possible when concatenated.
*/
static bool myComp(const string& a, const string& b) {
    string t1 = a + b;  // Concatenate a followed by b
    string t2 = b + a;  // Concatenate b followed by a
    return t1 > t2;     // Sort in descending order based on concatenated value
}

/*
    Function: largestNumber
    Purpose: Arrange numbers to form the largest possible concatenated number.
    Input: vector<int>& nums → list of integers
    Output: string → largest number formed by arranging nums

    Steps:
    1. Convert each integer to a string so we can compare concatenated results.
    2. Sort the string numbers using our custom comparator (myComp).
    3. Handle the special case where the largest number is "0" (meaning all are zero).
    4. Concatenate all sorted string numbers into the final result.
*/
string largestNumber(vector<int>& nums) {
    vector<string> snums;  // Store numbers as strings

    // Step 1: Convert all integers to strings
    for (auto n : nums) {
        snums.push_back(to_string(n));
    }

    // Step 2: Sort using custom comparator to get largest number order
    sort(snums.begin(), snums.end(), myComp);

    // Step 3: Special case - if the largest number after sorting is "0"
    // That means all numbers are zero (e.g., [0, 0, 0])
    if (snums[0] == "0") return "0";

    // Step 4: Concatenate all strings to form the largest number
    string result = "";
    for (auto& s : snums) {
        result += s;
    }

    return result; // Return the final largest number as a string
}

int main() {
    // Example input
    vector<int> nums = { 3, 30, 34, 5, 9 };

    // Output: 9534330 (largest number that can be formed)
    cout << largestNumber(nums) << endl;

    return 0;
}
